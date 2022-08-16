class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        int ans=-1;
        for(int i=s.size()-1;i>=0;i--){
            
                mp[s[i]]++;
            
            
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};