//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
  vector<int>primes;
 void check(){
      
      primes.assign(10000 + 1 , 1);
      int n = 1e4;
      for(int i = 2 ; i * i <= 1e4 ; i++){
          if(primes[i]){
              
              for(int j = i * i ; j <= 1e4 ; j += i){
                  primes[j] = 0;
              }
          }
      }
  }
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        check();
        queue<int>q;
        q.push(Num1);
        int lvl = 0;
        unordered_map<int , int> vis;
        vis[Num1] = 0;
        while(!q.empty()){
           
                int f = q.front();
                
                q.pop();
                for(int i = 0 ; i < 4 ; i++){
                    for(char j = '0' ; j <= '9' ; j++){
                        string cur = to_string(f);
                        if(i == 0 and j == '0')continue;
                        cur[i] = j;
                        int c = stoi(cur);
                        bool flag = primes[c];
                        if(!flag)continue;
                        if(vis.find(c) != vis.end() )continue;
                        vis[c] = vis[f] + 1;
                        if(flag )
                        q.push(c);
                    }
                }
            
        
        }
        return vis[Num2];
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends