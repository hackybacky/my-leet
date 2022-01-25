class Solution {
public:
    int bitmap(string words){
        int ans=0;
        for(auto it:words){
            ans|=(1<<(it-'a'));
        }
        return ans;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> words_map;
        
        for(auto it : words){
            
            words_map[bitmap(it)]++;
        }
        vector<int>ans;
        for(auto it :puzzles ){
            int msk , mskcur=bitmap(it);
            msk=mskcur;
            int first = bitmap(it.substr(0,1));
            int cnt=0;
            for(msk=mskcur; msk >=1;msk=(msk-1)&mskcur){
                if( words_map.find(msk)!=words_map.end() and first&msk){
                    cnt+=words_map[msk];
                    
                }
                
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};