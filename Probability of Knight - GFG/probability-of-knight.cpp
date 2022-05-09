// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int n;
	vector<int> dx = {1, 2, 2, 1, -1, -2, -2, -1 };
    vector<int> dy = { 2, 1, -1, -2, -2, -1, 1, 2 };
    double dp[101][101][101];
	double findAns(int x ,int y , int step){
	  //  cout<<x<<" "<<y<<" "<<step<<" "<<dp[x][y][step]<<endl;
	    if( x <0 or y<0 or y >=n or x>=n )return 0;
	    if(step<=0)return 1;
	    if(dp[x][y][step]!=-1)return dp[x][y][step];
	    double cnt=0;
	    //cout<<"hello"<<endl;
	    for(int j=0; j<8; j++){
	        cnt+=findAns(x+dx[j],y+dy[j],step-1);
	    }
	   // cout<<cnt<<endl;
	    return dp[x][y][step]=cnt/8;
	    
	}
	double findProb(int N,int start_x, int start_y, int steps)
	
	{   
	   //(dp,sizeof(dp),-1.9
	   for(int i=0; i<=100; i++){
	       for(int j=0; j<=100; j++){
	           for(int k=0; k<=100;k++)dp[i][j][k]=-1;
	       }
	   }
	    n=N;
	    return (findAns(start_x , start_y , steps));
	  
	   
	 // return total;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends