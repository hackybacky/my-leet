class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int str_len= s.size();
        int maxf=0;
        map<char,int>count;
        for(int j=0; j<str_len ; j++){
            maxf=max(maxf,++count[s[j]]);
            
            if(j-i+1>k+maxf){
                count[s[i++]]--;
            }
        }
        
        return str_len-i;
    }
};