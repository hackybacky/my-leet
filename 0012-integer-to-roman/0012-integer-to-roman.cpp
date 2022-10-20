class Solution {
public:
    string intToRoman(int num) {
        string s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int sz = 13;
        // cout<<val[1];
        string ans="";
        for(int i=0;i<sz;i++){
            
            while(num>=val[i]){
                num-=val[i];
                ans+=s[i];
            }
        }
        return ans;
    }
};