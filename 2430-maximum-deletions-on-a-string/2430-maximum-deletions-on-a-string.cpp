class Solution {
public:
    const long long int m = 1e9 + 9;
    vector<int>dp;
    int recur(int i , vector<long long int > &h , string &s ,vector<long long int >&pw){
        int n = s.size();
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = 1;
        for(int j = i ; j < n ; j++){
            int len = j - i + 1;
            int slen = n - 1 - j;
            if(slen < len)
                break;
            long long hsuf = (h[j + len] - h[j] + m) % m;
            long long hpref = (h[j] - (i - 1>=0?h[i - 1] : 0) + m) % m;
            hsuf = (hsuf * pw[i])%m;
            hpref = (hpref * pw[j + 1]) % m;
            // cout << "hello " <<  hpref << " " << hsuf  << endl;
            if(hsuf == hpref){
                ans = max(ans , 1 + recur(j + 1 , h , s , pw));
            }
            
        }
    
        return dp[i] = ans;
    }
    int deleteString(string s) {
        int n = s.size();

        const int p = 31;
        vector<long long> p_pow(n);
        p_pow[0] = 1;
        for (int i = 1; i < n; i++)
            p_pow[i] = (p_pow[i-1] * p) % m;

        vector<long long> h(n + 1, 0);
        for (int i = 0; i < n; i++)
            h[i] = ((i - 1 >=0 ?h[i - 1] :0) + (s[i] - 'a' + 1) * p_pow[i]) % m;
        
        dp.assign(n , -1);
        return recur(0 , h , s , p_pow);
    }
};