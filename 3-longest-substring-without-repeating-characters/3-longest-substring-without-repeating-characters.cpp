class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=-1;
        int n=s.size();
        vector<int> indi(2777,-1);
        int ans=0;
        //ayush code mat dekh
        for(int i=0 ; i< n ;i++){
            start=max(indi[s[i]],start);
            indi[s[i]]=i;
            ans=max(ans,i-start);
        }
        
        return ans;
    }
};
