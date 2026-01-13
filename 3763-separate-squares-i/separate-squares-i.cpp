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

 double calculateAreaBelow(vector<vector<int>>& squares, double y_line) {
        double below = 0;
        for (const auto& s : squares) {
            double y1 = s[1];
            double l = s[2];
            double y2 = y1 + l;
            if (y2 <= y_line) { 
                below += l * l;
            } else if (y1 < y_line) {
                double height = y_line - y1;
                below += height * l;
            }
        }
        return below;
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<int>y;
        // for(const auto& s : squares){
        //     int y1 = s[1];
        //     int y2 = y1 + s[2];
        //     y.push_back(y1);
        //     y.push_back(y2);
        // }
        // sort(y.begin(), y.end());
        // double left = y.front(), right = y.back(), mid;
        // while (right - left > 1e-6) {
        //     mid = (left + right) / 2.0;
        //     auto [above, below] = total_area(squares, mid);
        //     if (above > below) {
        //         right = mid;
        //     } else {
        //         left = mid;
        //     }
        // }
        // return left;
        double total_area = 0;
        for (const auto& s : squares) {
            double l = s[2];
            total_area += l * l;
        }
        double left = 0, right = 0;
        for (const auto& s : squares) {
            right = max(right, static_cast<double>(s[1] + s[2]));
        }
        double epsilon = 1e-5;
        while (right - left > epsilon) {
            double mid = (left + right) / 2.0;
            double below = calculateAreaBelow(squares, mid);
            if (below < total_area / 2) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};