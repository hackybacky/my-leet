class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cntp(27,0);
        
        for(auto it : p){
            cntp[it-'a']++;
        }
        vector<int> ans;
       vector<int> cnts(27,0);
        int k=p.size();
        for(int i=0; i<s.size(); i++){
            if(i-k>=0)cnts[s[i-k]-'a']--;
            
            cnts[s[i]-'a']++;
            if(cnts==cntp){
                ans.push_back(i-k+1);
            }
        }
        
        return ans;
        
    }
};