class Solution {
public:
    
    const int p = 31;
    const int mod = 1e9 + 7;
    vector<int> rabinKarp(string &txt){
        int n = txt.size();
        vector<int>arr(n , 0);
        int pw = 1;
        for(int i = 0 ; i < n ; i++){
            arr[i] = ((long long)(txt[i] - 'a' + 1)* (long long)pw )% mod;
            pw = ((long long)pw * (long long)p)% mod;
        }
        
        return arr;
    }
    int distinctEchoSubstrings(string text) {
        // kmp(text);
        int n = text.size();
        int ans = 0;
        vector<int>pw(n , 0);
        pw[0] = 1;
        for(int i = 1 ; i < n; i++)pw[i] = ((long long)pw[i - 1] * (long long)p)%mod;
        unordered_map<string, int > mp;
        for(int i = 0 ; i < n - 1 ;i++){
            string cur(text.begin() + i , text.end());
            auto hash = rabinKarp(cur);
            for(int j = i + 1 ; j < n ;j++){
                int len = j - i + 1;
                if(len % 2 == 1)continue;
                int half = len / 2;
                
                int current = j - i;
                int left = ((long long)hash[half - 1] * (long long)pw[half])% mod;
                if(left == hash[len - 1] ){
                   // ans++;
                    
                    string cur2 = string(text.begin() + i , text.begin() + j + 1) ;
                    if(cur2.substr(0 , half) == cur2.substr(half  ) and mp[cur2] == 0)ans++, mp[cur2]++;
                }
            }
        }
        return ans;
        return 1;
    }
};