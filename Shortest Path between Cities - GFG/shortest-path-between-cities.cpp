// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int recur( int x , int y , int a , int b ){
        
        if(x==y)return a+b;
        if( x>y){
            x/=2,a++;
        }
        else if( y>x){
            y/=2,b++;
        }
        
        return recur(x,y,a,b);
    }
    int shortestPath( int x, int y){ 
        // code here 
        return recur(x,y,0,0);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends