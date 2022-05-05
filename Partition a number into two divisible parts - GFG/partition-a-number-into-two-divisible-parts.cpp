// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    bool isdiv(string &s1, string &s2, int a, int b){
       int val1 = stoi(s1);
       int val2 = stoi(s2);
       if( ( val1 %a==0 ) and (val2 %b==0)) return true;
       return false;
   }
   string stringPartition(string s, int a, int b){
       int n =s.size();
       for(int i=0;i<n-1;i++){
           string s1 = s.substr(0,i+1);
           string s2 =s.substr(i+1, n-i-1);
           if(isdiv(s1,s2,a,b))   
               return s1+" "+s2;
       }
       return "-1";
   }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends