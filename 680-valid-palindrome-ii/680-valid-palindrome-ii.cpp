class Solution {
public:
    bool isValidPalindrome(string s){
        string ds =s ;
        reverse((ds).begin(),ds.end());
        return ds==s;
    }
    bool validPalindrome(string s) {
        
        int i=0;
        int j = s.size();
        j--;
        int cnt=0;
        while(i<j){
            if(s[i]==s[j])i++,j--;
            else{
                
                return isValidPalindrome(string(s.begin()+i,s.begin()+j)) || 
                    isValidPalindrome(string(s.begin()+i+1,s.begin()+j+1));
            }
        }
        return true;
    }
};