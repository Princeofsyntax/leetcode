class Solution {
private:
    vector<int> tree;

    void build(int node, int start, int end, const vector<int>& baskets) {
        if (start == end) {
            tree[node] = baskets[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, baskets);
        build(2 * node + 1, mid + 1, end, baskets);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            tree[node] = 0;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx);
        } else {
            update(2 * node + 1, mid + 1, end, idx);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int find_leftmost(int node, int start, int end, int fruit_size) {
        if (tree[node] < fruit_size) {
            return -1;
        }
        if (start == end) {
            return start;
        }
        int mid = start + (end - start) / 2;
        if (tree[2 * node] >= fruit_size) {
            return find_leftmost(2 * node, start, mid, fruit_size);
        }
        return find_leftmost(2 * node + 1, mid + 1, end, fruit_size);
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        if (n == 0) {
            return fruits.size();
        }

        tree.assign(4 * n, 0);
        build(1, 0, n - 1, baskets);

        int unplaced_count = 0;
        for (int fruit_size : fruits) {
            int basket_idx = find_leftmost(1, 0, n - 1, fruit_size);

            if (basket_idx != -1) {
                update(1, 0, n - 1, basket_idx);
            } else {
                unplaced_count++;
            }
        }
        return unplaced_count;
    }
};