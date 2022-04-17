// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    #define ll long long
    
    //Given half palindrome, returns integer representing complete palindrome
    ll returnPalindrome(int num, bool isOdd) {
        string str = to_string(num);
        int n = str.size(), i = n-1;
        
        //if odd size, don't repeat the middle element
        if(isOdd) 
            i--;
        
        //complete palindrome
        while(i >= 0) 
            str += str[i--];
        
        //convert to int and return
        ll ans = stoll(str);
        return ans;
    }
    
    //Checks for nums like 10, 100, 1000 ....
    bool isMultiple10(int num) {
        while(num and ((num % 10) == 0)) 
            num /= 10;
        return num == 1;
    }

	ll closestPalindrome(ll num){
	    //Self Palindromes till 9
	    if(num <= 9) 
	        return num;
    
       //Check for numbers of the form 10..00
       //These numbers have a closest palindrome with size less than there own size
       //Bcoz for other numbers, from 10....0x where (x > 0), 10....01 will be a palindrome  
       //so we will not have to decrease the size of palindrome in any other case
	   if(isMultiple10(num)) 
	    return (num - 1);
	    
	    string str = to_string(num);
	    string palin = "";
	    int n = str.size();
	    bool isOdd = n & 1 ? true : false;
        
        //Make a half palindrome	    
        for(int i=0; i<n/2; i++) 
            palin += str[i];
        if(isOdd)
            palin += str[n/2];
        
        //Check the following three possibilities
        ll x = stoll(palin);
                
        ll ans = returnPalindrome(x, isOdd);
        ll ans1 = returnPalindrome(x-1, isOdd);        
        ll ans2 = returnPalindrome(x+1, isOdd);        
        
        //Compare the following three possibilities and return the optimal one
        if(abs(ans - num) >= abs(ans1 - num)) 
            ans = ans1;

        if(abs(ans - num) > abs(ans2 - num))
            ans = ans2;
        
        return ans;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends