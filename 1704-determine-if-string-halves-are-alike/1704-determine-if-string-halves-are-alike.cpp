class Solution {
public:
    bool isvowel(char c){
        c = tolower(c);
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
    int check(string &s , int start , int end){
        int cnt = 0;
        for(int i = start ; i < end ; i++){
            if(isvowel(s[i])){
                cnt++;
            }
        }
        return cnt;
    }
    bool halvesAreAlike(string s) {
        int sz = s.size();
        int n = check(s , 0 , sz / 2);
        int n2 = check(s , sz / 2 , sz);
        return n  == n2;
    }
};