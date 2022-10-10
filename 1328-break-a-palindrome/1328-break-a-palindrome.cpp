class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        bool flag = false;
        for(auto it : palindrome){
            if(it != 'a'){
                flag = true;
            }
        }
        if(palindrome.size() == 1){
            return "";
        }
        if(flag == false and palindrome.size() == 1){
            return "";
            
        }
        int n = palindrome.size();
        if(!flag){
            palindrome[n - 1] = 'b';
            return palindrome;
        }
        bool found = false;
        char c = 'a';
        for(int i = 0 ; i < palindrome.size() ; i++){
            if(palindrome[i] != 'a'){
                char prev = palindrome[i];
                palindrome[i] = c;
                string rv = palindrome;
                reverse(rv.begin() , rv.end());
                if(rv == palindrome){
                    c++;
                    palindrome[i] = prev;
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