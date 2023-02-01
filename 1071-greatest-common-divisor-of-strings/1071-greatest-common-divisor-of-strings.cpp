class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int sz = str1.size();
        int sz2 = str2.size();
        int g = __gcd(sz , sz2);
        
        if(str1 + str2 == str2 + str1){
            return str1.substr(0 , g);
        }
        return "";
    }
};