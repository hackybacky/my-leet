class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        auto cs = s;
        
        reverse(cs.begin(),cs.end());
        
        if(cs == s)return 1;
        else return 2;
    }
};