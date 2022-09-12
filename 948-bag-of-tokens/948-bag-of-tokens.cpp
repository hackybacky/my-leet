class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int left = 0 , right = n - 1;
        int token = 0;
        sort(tokens.begin() , tokens.end());
        while(left <= right){
            if( tokens[left] <= power)
                token++ , power -= tokens[left] , left++;
            else{
                // cout << token << " " << right << endl;
                if( token > 0 and left < right ) 
                    power += tokens[right--] , token--;
                else break;
                cout << power << endl;
            }
                
        }
        return token;
    }
};