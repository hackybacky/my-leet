class Solution {
public:
    struct Hash {
    const int p = 31, m = 1e9 + 7;
    int hash_value;
    Hash(const string& s) {
        int hash_so_far = 0;
        long p_pow = 1;
        const int n = s.length();
        for (int i = 0; i < n; ++i) {
            hash_so_far = (hash_so_far + (s[i] - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        hash_value = hash_so_far;
    }
    bool operator==(const Hash& other) {
        return (hash_value == other.hash_value);
    }
};
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<long long int , int > mp;
        long long m = 1e12 + 7;
        for(auto it : words){
            long long int hash = 0;
            long long int po = 1;
            long long p = 37;
            for(int i = 0 ; i < it.size() ; i++){
                hash = (hash + (long long)(it[i] - 'a' + 1)*po) % m;
                po = (po * p) % m;
                 
                mp[ hash ]++;
            }
        }
        vector<int>ans;
        for(auto it : words){
            long long int hash = 0;
            long long int po = 1;
            long long int p = 37;
            int c = 0;
            for(int i = 0 ; i < it.size() ; i++){
                hash = (hash + (long long)(it[i] - 'a' + 1)*po) % m;
                po = (po * p) % m;
                
                
                c += mp[hash];
            }
            ans.push_back(c);
        }
        return ans;
    }
};