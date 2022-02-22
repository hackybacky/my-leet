class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char,int> ch;
        for(auto it : chars) ch[it]++;
        int ans=0;
        
        for(auto it : words){
            unordered_map<char,int> cur;
            
            for(auto it2 : it)cur[it2]++;
            
            for(auto it : cur){
                if(ch[it.first]<it.second){
                    goto next;
                }
            }
            ans+=it.size();
            next:;
        }
        return ans;
    }
};