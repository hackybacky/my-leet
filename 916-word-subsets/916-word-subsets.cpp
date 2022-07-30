class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> hash_w2(26,0);
        
        for(auto it : words2){
            vector<int>hash_cur(26,0);
            for(auto i : it){
                hash_cur[i-'a']++;
            }
            for(int i=0;i<26 ;i++)hash_w2[i]=max(hash_w2[i] , hash_cur[i]);
        }
        
        vector<string>ans;
        
        for(auto it : words1){
            vector<int> hash_cur(26,0);
            for(auto i : it){
                hash_cur[i-'a']++;
            }
            
            for(int i=0;i<26 ;i++){
                if( hash_w2[i]>hash_cur[i] ) goto next;
            }
            ans.push_back(it);
            next:;
        }
        return ans;
    }
};