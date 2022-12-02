class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        map<char , int > mp;
        for(auto it : word1){
            mp[it]++;
        }
        
        
        multiset<int> ms, ms2;
        map<char , int > mp2;
        for(auto it : word2){
            mp2[it]++;
            if(mp[it] == 0){
                return false;
            }
        }
        for(auto it : mp){
            ms.insert(it.second);
            if(mp2[it.first] == 0){
                return false;
            }
        }
        
        for(auto it : mp2){
            ms2.insert(it.second);
        }
        return ms2 == ms;
    }
};