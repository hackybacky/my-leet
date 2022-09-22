class Solution {
public:
    string reverseWords(string s) {
        int i = 0 ; 
        int n = s.size();
        while( i < n ){
            int j = i;
            while( j < n and s[j] !=' ')j++;
            reverse(s.begin() + i , s.begin() + j);
            i = j + 1;
        }
        return s;
    }
};