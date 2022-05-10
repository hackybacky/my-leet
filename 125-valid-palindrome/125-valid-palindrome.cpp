class Solution {
public:
    bool isPalindrome(string s) {
        
        int l=0,r=s.size()-1;
        
        while(l<r){
           
            if(isalpha(s[l])==false and isdigit(s[l])==false){
                l++;
                continue;
            }
            if(isalpha(s[r])==false and isdigit(s[r])==false){
                r--;continue;
            }
            s[l]=tolower(s[l]);
            s[r]=tolower(s[r]);
           
            if(s[l]!=s[r])return false;
             
            l++,r--;
            
        }
        return true;
    }
};