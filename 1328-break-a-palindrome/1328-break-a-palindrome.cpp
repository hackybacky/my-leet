class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        
        if(palindrome.size() == 1){
            return "";
        }
        
        int n = palindrome.size();
        
        bool found = false;
        char c = 'a';
        for(int i = 0 ; i < palindrome.size() ; i++){
            if(palindrome[i] != 'a'){
                char prev = palindrome[i];
                palindrome[i] = c;
                string rv = palindrome;
                reverse(rv.begin() , rv.end());
                if(rv == palindrome){
                    palindrome[i] = prev;
                   break;
                }
                else{
                    found = true;
                    break;
                }
            }
        }
        if(!found){
            palindrome[n - 1] = 'b';
        }
        return palindrome;
    }
};