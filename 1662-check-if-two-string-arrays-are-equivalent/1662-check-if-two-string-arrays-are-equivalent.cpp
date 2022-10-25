class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int i = 0 , j = 0;
        
        int indi = 0 , indib = 0;
        while(indi < word1.size() and indib < word2.size()){
            if(word1[indi][i] != word2[indib][j]){
                return false;
            }
            i++ , j++;
            if(i == word1[indi].size())
                i = 0 , indi++;
            if(j == word2[indib].size()){
                j = 0 , indib++;
            }
        }
        
        
        return indi == word1.size() and indib == word2.size();
    }
};