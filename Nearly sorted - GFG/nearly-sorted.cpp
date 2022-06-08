// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        priority_queue<int>pq;
        int n = num;
        int t=0;
        vector<int>ans(num,0);
        
        while(1){
            if(t<K){pq.push(-arr[t]);t++;continue;}
            else if(t<n)pq.push(-arr[t]);
            if(pq.empty())break;
            int top = -pq.top();
            pq.pop();
            // cout<<top<<endl;
            ans[t-K]=top;
            t++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends