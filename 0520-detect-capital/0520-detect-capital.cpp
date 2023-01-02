class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int cntupper = 0;
        for(auto it : word){
            if(isupper(it))cntupper++;
        }
        
        return cntupper == word.size() or (cntupper == 1 and isupper(word[0])) or cntupper == 0;
    }
};