// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends


vector<int> permute(vector<vector<int>> &arr, int n)
{
    
    // Complete the function
    
    vector<pair<int,int>> time_arr;
    int i=0;
    for(auto it : arr){
        int cur_su =0; 
        for(auto it2:it)cur_su+=it2;
        
        time_arr.push_back({cur_su,i});
        i++;
    }
    
    sort(time_arr.begin(),time_arr.end());
    
    vector<int> final_ans;
    
    for(auto it : time_arr){
        final_ans.push_back(it.second+1);
        
    }
    
    return final_ans;
    

    
    
    
    
    
    
}