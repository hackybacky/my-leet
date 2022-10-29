class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,int>mp;
        int last=-1;
        int n = s.size();
        int ans=0;
        for(int i=0 ; i<n; i++){
           if(mp.find(s[i]) != mp.end())
            last = max(last  ,mp[s[i]] );
            mp[s[i]] = i;
            
            ans = max(ans , i - last);
        }
        return max(ans,n-last-1);
    }
};