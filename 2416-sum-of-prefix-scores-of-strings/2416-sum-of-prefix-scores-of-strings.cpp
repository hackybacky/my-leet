class Solution {
public:
    
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<long long int , int > mp;
        long long m = 1e14 + 7;
        for(auto it : words){
            long long int hash = 0;
            long long int po = 1;
            long long p = 37;
            for(int i = 0 ; i < it.size() ; i++){
                hash = (hash + (it[i] - 'a' + 1)*po) % m;
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