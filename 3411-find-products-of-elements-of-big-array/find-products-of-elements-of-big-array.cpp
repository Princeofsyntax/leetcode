using ll = long long;

const int MAX_BITS = 50;

ll count_powers[MAX_BITS + 1];
ll sum_powers[MAX_BITS + 1];
ll power_of_two = 1;

auto init = [] {
    count_powers[0] = 0;
    sum_powers[0] = 0;
    for (int i = 1; i <= MAX_BITS; ++i) {
        count_powers[i] = count_powers[i - 1] * 2 + power_of_two;
        sum_powers[i] = sum_powers[i - 1] * 2 + power_of_two * (i - 1);
        power_of_two *= 2;
    }
    return 0;
}();

pair<ll, ll> calculateIndexAndSum(ll x) {
    ll idx = 0;
    ll totalSum = 0;
    while (x > 0) {
        int bitPos = 63 - __builtin_clzll(x);
        idx += count_powers[bitPos];
        totalSum += sum_powers[bitPos];
        x -= 1LL << bitPos;
        totalSum += (x + 1) * bitPos;
        idx += x + 1;
    }
    return make_pair(idx, totalSum);
}

ll calculateTotalSum(ll i) {
    ll low = 0;
    ll high = 1LL << MAX_BITS;
    while (low < high) {
        ll mid = (low + high + 1) >> 1;
        auto idxAndSum = calculateIndexAndSum(mid);
        ll idx = idxAndSum.first;
        if (idx < i) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    auto idxAndSum = calculateIndexAndSum(low);
    ll totalSum = idxAndSum.second;
    ll idx = idxAndSum.first;
    i -= idx;
    ll x = low + 1;
    for (int j = 0; j < i; ++j) {
        ll y = x & -x;
        totalSum += __builtin_ctzll(y);
        x -= y;
    }
    return totalSum;
}

ll modPow(ll base, ll exp, ll mod) {
    ll result = 1 % mod;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

class Solution {
public:
    vector<int> findProductsOfElements(vector<vector<ll>>& queries) {
        int queryCount = queries.size();
        vector<int> result(queryCount);
        for (int i = 0; i < queryCount; ++i) {
            ll left = queries[i][0];
            ll right = queries[i][1];
            ll mod = queries[i][2];
            ll power = calculateTotalSum(right + 1) - calculateTotalSum(left);
            if (power < 0) {
                power += mod;
            }
            result[i] = static_cast<int>(modPow(2, power, mod));
        }
        return result;
    }
};
