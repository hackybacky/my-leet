class Solution {
public:
    int titleToNumber(string columnTitle) {
          int ans=0;
        long long  base=1;
        reverse(columnTitle.begin(),columnTitle.end());
        for(char it : columnTitle){
            ans+=(it-'A'+1)*base;
            base*=26;
        }
        
        return ans;
    }
};