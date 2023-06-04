typedef long long int  ll;
class Solution {
public:
    bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}
 
// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        // If subtraction is less than zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
    ll dp[23][401][2];
    int mod = 1e9 + 7;
    int mn  , mx;
    ll recur(int i  , int cursum , string &s , int flag ){
        if(i == s.size()){
            if(cursum <= mx and cursum >= mn){
                return 1;
            }
            else return 0;
        }
        if(cursum > mx )return 0;
        if(dp[i][cursum][flag] != -1)return dp[i][cursum][flag];
        int upper_bound = flag ? (s[i] - '0') : 9;
        int ans = 0;
        for(int digit = 0 ; digit <= upper_bound ; digit++){
            ans = (recur(i + 1 , cursum + digit , s , flag & (digit == upper_bound)) + ans)% mod;
        }
        return dp[i][cursum][flag] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        mn = min_sum , mx = max_sum ;
        memset(dp , -1 ,sizeof(dp));
        string temp = findDiff(num1 , "1");
        int cur = recur(0 , 0 , num2 , 1  )% mod;
        memset(dp , -1 ,sizeof(dp));
        return (cur - recur(0 , 0 , temp , 1) + mod)% mod ;
    }
};