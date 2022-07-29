class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto it : words){
            string cur = it;
            
            unordered_map<char,char>mp;
            unordered_map<char,char>r;
            for(int i=0  ; i< pattern.size()  ;i++ ){
                if(mp.find(pattern[i])!=mp.end() or r.find(cur[i])!=r.end()){
                    if(mp[pattern[i]]!=cur[i] or r[cur[i]]!=pattern[i]){
                        goto next;
                    }
                }
                else mp[pattern[i]]=cur[i],r[cur[i]]=pattern[i];
            }
            ans.push_back(cur);
            next:;
        }
        return ans;
    }
};