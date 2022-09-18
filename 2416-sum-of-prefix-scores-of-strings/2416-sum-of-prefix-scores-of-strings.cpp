class Solution {
public:
    
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<long long int , int > mp;
        long long mod = 1e14 + 7;
        for(auto it : words){
            long long int key = 0;
            
            for(int i = 0 ; i < it.size() ; i++){
                key = (((key<<7) + key) ^ (it[i] - 'a' + 1))%mod;
                 
                mp[ key ]++;
            }
        }
        vector<int>ans;
        for(auto it : words){
            long long int key = 0;
            
            int c = 0;
            for(int i = 0 ; i < it.size() ; i++){
                // hash = (hash + (it[i] - 'a' + 1)*po) % m;
                key = (((key << 7) + key) ^ (it[i] - 'a' + 1))%mod;
            
                
                
                c += mp[key];
            }
            ans.push_back(c);
        }
        return ans;
    }
};