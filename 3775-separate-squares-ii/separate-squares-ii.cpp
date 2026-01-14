class Solution {
public:
     pair<double,double> total_area(vector<vector<int>>& squares, double y_line){
        double above = 0; 
        double below = 0;
        for(const auto & s : squares){
            int y1 = s[1];
            int l = s[2];
            int y2 = y1 + l;
            double area = l*l;
            if(y2 <= y_line){
                below += area;
            }
            else if(y1 >= y_line){
                above += area;
            }
            else{
                // double above_f = (y2 - y_line)/(double)l;
                // above += area * above_f;
                // below += area * (1 - above_f);
                double below_fraction = (y_line - y1) / (double)l;
                below += area * below_fraction;
                above += area * (1 - below_fraction);
            }
        }
        return {above,below};
    }

    void updateTheLenght(vector<int> &cnt, vector<double> &len, vector<double> &x, int i, int l, int r, int ql, int qr, int v) {
    if (ql >= r || qr <= l) return;
    if (ql <= l && r <= qr) cnt[i] += v;
     else{
        int m = (l + r) / 2;
        updateTheLenght(cnt, len, x, i * 2, l, m, ql, qr, v);
        updateTheLenght(cnt, len, x, i * 2 + 1, m, r, ql, qr, v);
    }
    len[i] = cnt[i] ? x[r] - x[l] : (r - l > 1 ? len[i * 2] + len[i * 2 + 1] : 0.0);
}

 void adjust(vector<int> &flags, vector<double> &ranges, vector<double> &points, int idx, int start, int end, int qs, int qe, int delta) {
        if (qs >= end || qe <= start) return;
        if (qs <= start && end <= qe) flags[idx] += delta;
        else {
            int mid = (start + end) / 2;
            adjust(flags, ranges, points, idx * 2, start, mid, qs, qe, delta);
            adjust(flags, ranges, points, idx * 2 + 1, mid, end, qs, qe, delta);
        }
        ranges[idx] = flags[idx] ? points[end] - points[start] : (end - start > 1 ? ranges[idx * 2] + ranges[idx * 2 + 1] : 0.0);
    }

    double separateSquares(vector<vector<int>>& squares) {
        // vector<double> x;
        // for (auto &s : squares) {
        //     double a = s[0], b = s[2];
        //     x.push_back(a);
        //     x.push_back(a + b);
        // }
        // sort(x.begin(), x.end());
        // x.erase(unique(x.begin(), x.end()), x.end());
        // int n = x.size();
    
        struct keepSimple {
            double y;
            int f, l, r;
        };
        vector<keepSimple> e;
        // for (auto &s : squares) {
        //     double a = s[0], b = s[1], c = s[2];
        //     int l = lower_bound(x.begin(), x.end(), a) - x.begin();
        //     int r = lower_bound(x.begin(), x.end(), a + c) - x.begin();
        //     e.push_back({b, 1, l, r});
        //     e.push_back({b + c, -1, l, r});
        // }
    
        // sort(e.begin(), e.end(), [](E &p, E &q) {
        //     return p.y == q.y ? p.f > q.f : p.y < q.y;
        // });
        // vector<int> cnt(4 * n, 0);
        // vector<double> len(4 * n, 0.0);
        // struct S {
        //     double y1, y2, w, a;
        // };
        // vector<S> seg;
        // double py = 0.0, area = 0.0, w = 0.0;
        // int i = 0, m = e.size();
        // if (m > 0 && e[0].y > 0.0) {
        //     seg.push_back({0.0, e[0].y, 0.0, area});
        //     py = e[0].y;
        // }
        // while (i < m) {
        //     double cy = e[i].y;
        //     if (cy > py) {
        //         seg.push_back({py, cy, w, area});
        //         area += w * (cy - py);
        //         py = cy;
        //     }
        //     while (i < m && fabs(e[i].y - cy) < 1e-12) {
        //         update(cnt, len, x, 1, 0, n, e[i].l, e[i].r, e[i].f);
        //         i++;
        //     }
        //     w = len[1];
        // }
        // double half = area / 2.0, midY = 0.0;
        // for (auto &s : seg) {
        //     double y1 = s.y1, y2 = s.y2, w = s.w, a = s.a;
        //     double sa = w * (y2 - y1);
        //     if (half <= a) {
        //         midY = y1;
        //         break;
        //     }
        //     if (a < half && half <= a + sa) {
        //         midY = fabs(w) < 1e-12 ? y1 : y1 + (half - a) / w;
        //         break;
        //     }
        //  }
        // return midY;
         vector<double> points;
        for (auto &s : squares) {
            double x = s[0], len = s[2];
            points.push_back(x);
            points.push_back(x + len);
        }
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        int total = points.size();
    
        struct Change {
            double y;
            int kind, left, right;
        };
        vector<Change> updates;
        for (auto &s : squares) {
            double x = s[0], y = s[1], len = s[2];
            int left = lower_bound(points.begin(), points.end(), x) - points.begin();
            int right = lower_bound(points.begin(), points.end(), x + len) - points.begin();
            updates.push_back({y, 1, left, right});
            updates.push_back({y + len, -1, left, right});
        }
    
        sort(updates.begin(), updates.end(), [](Change &a, Change &b) {
            return a.y == b.y ? a.kind > b.kind : a.y < b.y;
        });
    
        vector<int> flags(4 * total, 0);
        vector<double> ranges(4 * total, 0.0);
    
        struct Interval {
            double low, high, width, accumulated;
        };
        vector<Interval> intervals;
        double lastY = 0.0, fullArea = 0.0, currWidth = 0.0;
        int idx = 0, numEvents = updates.size();
    
        if (numEvents > 0 && updates[0].y > 0.0) {
            intervals.push_back({0.0, updates[0].y, 0.0, fullArea});
            lastY = updates[0].y;
        }
        while (idx < numEvents) {
            double currY = updates[idx].y;
            if (currY > lastY) {
                intervals.push_back({lastY, currY, currWidth, fullArea});
                fullArea += currWidth * (currY - lastY);
                lastY = currY;
            }
            while (idx < numEvents && fabs(updates[idx].y - currY) < 1e-12) {
                adjust(flags, ranges, points, 1, 0, total, updates[idx].left, updates[idx].right, updates[idx].kind);
                idx++;
            }
            currWidth = ranges[1];
        }
    
        double halfArea = fullArea / 2.0, result = 0.0;
        for (auto &interval : intervals) {
            double low = interval.low, high = interval.high, width = interval.width, accumulated = interval.accumulated;
            double intervalArea = width * (high - low);
            if (halfArea <= accumulated) {
                result = low;
                break;
            }
            if (accumulated < halfArea && halfArea <= accumulated + intervalArea) {
                result = fabs(width) < 1e-12 ? low : low + (halfArea - accumulated) / width;
                break;
            }
        }
        return result;
    }
};