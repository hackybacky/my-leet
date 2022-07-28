class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int>hash_s(26,0);
        
        auto hash_t = hash_s;
        
        for(auto it : s )hash_s[it-'a']++;
        for(auto it : t ) hash_t[it-'a']++;
        
        return hash_t==hash_s;
        
    }
};