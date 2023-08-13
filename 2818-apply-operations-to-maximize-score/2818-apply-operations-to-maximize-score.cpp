int memo[100001] = {}, mod = 1000000007;
const int primes[65] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 
    137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 
    227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};  
class Solution {
public:
    int modPow(int x, unsigned int y, unsigned int m)
    {
        if (y == 0)
            return 1;
        long p = modPow(x, y / 2, m) % m;
        p = (p * p) % m;
        return y % 2 ? (p * x) % m : p;
    }
    int primeScore(int n) {
        if (memo[n])
            return memo[n];
        int score = 0, val = n;
        for (int i = 0; i < 65 && n >= primes[i]; ++i)
            if (val % primes[i] == 0) {
                ++score;
                while (val % primes[i] == 0)
                    val /= primes[i];
            }
        return memo[n] = score + (val > 1);
    }
    int maximumScore(vector<int>& n, int k) {
        long long res = 1, sz = n.size();
        vector<int> ids(sz), l(sz), r(sz), score_l(8, -1), score_r(8, sz);
        for (int i = 0; i < sz; ++i) {
            int score = primeScore(n[i]);
            l[i] = *max_element(begin(score_l) + score, end(score_l));
            score_l[score] = i;
        }
        for (int i = sz - 1; i >= 0; --i) {
            int score = primeScore(n[i]);
            r[i] = *min_element(begin(score_r) + score + 1, end(score_r));
            score_r[score] = i;
        }
        auto comp = [&](int i, int j){ return n[i] < n[j]; };
        iota(begin(ids), end(ids), 0);
        make_heap(begin(ids), end(ids), comp);
        while (!ids.empty() && k > 0) {
            int i = ids.front();
            pop_heap(begin(ids), end(ids), comp); ids.pop_back();
            long long take = min(k, (i - l[i]) * (r[i] - i));
            res = (res * modPow(n[i], take, mod)) % mod;
            k -= take;
        }
        return res;
    }
};