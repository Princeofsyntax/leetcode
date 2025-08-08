class Memo {
public:
    // unordered_map for memoization
    unordered_map<int, unordered_map<int, double>> mem;

    double get(int a, int b) {
        if (mem.count(a) && mem[a].count(b)) return mem[a][b];
        return -1.0;
    }
    void set(int a, int b, double val) {
        mem[a][b] = val;
    }
};

// Forward declaration
double soupDp(int a, int b, Memo* memo);

// The recursive function, now a regular function
double soupDp(int a, int b, Memo* memo) {
    if (a <= 0 && b <= 0) return 0.5;    // Both empty at same time
    if (a <= 0) return 1.0;              // A finishes first
    if (b <= 0) return 0.0;              // B finishes first
    double ret = memo->get(a, b);
    if (ret >= -0.5) return ret;         // Already computed

    ret = 0.25 * (
        soupDp(a - 4, b, memo) +        // pour 100 mL from A, 0 from B
        soupDp(a - 3, b - 1, memo) +    // pour 75 mL from A, 25 from B
        soupDp(a - 2, b - 2, memo) +    // pour 50 mL from A, 50 from B
        soupDp(a - 1, b - 3, memo)      // pour 25 mL from A, 75 from B
    );
    memo->set(a, b, ret);
    return ret;
}

class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0; // Asymptotic result

        n = (int)ceil(n / 25.0); // Convert to units of 25 mL

        Memo memo;
        return soupDp(n, n, &memo);
    }
};