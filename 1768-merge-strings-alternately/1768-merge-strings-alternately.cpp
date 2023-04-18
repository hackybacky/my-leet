class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size() ,m = word2.size();
        
        string ans = "";
        int i = 0 , j = 0;
        while(i < n and j < m ){
            ans += word1[i++];
            ans += word2[j++];
        }
        if(j < m )swap(i , j) , swap(word1  , word2);
        while(i  < word1.size() )ans += word1[i++];
        return ans;
    }
};