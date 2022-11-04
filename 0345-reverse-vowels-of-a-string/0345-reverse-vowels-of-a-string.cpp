class Solution {
public:
    bool check(char c){
        c = tolower(c);
        if(c == 'a' or c == 'e' or c == 'i' or c == 'u' or c == 'o'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int first = 0 , last = 0;
        int n = s.size();
        last = n - 1;
        for(int i = 0 ; i < last ; i++){
            if(check(s[i])){
                while(last >=0 and !check(s[last])){
                    last--;
                }
                swap(s[i] , s[last]);
                last--;
            }
        }
        return s;
    }
};