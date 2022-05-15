// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int>>lans;
    void backtrack(vector<int>&nums,int i,vector<int>cur){
        
        if(i==nums.size()){lans.push_back(cur);return;}
        lans.push_back(cur);
        for(int j =i; j<nums.size(); j++){
        
                
                cur.push_back(nums[j]);
                backtrack(nums,j+1,cur);
                cur.pop_back();
                
                int k=j+1;
                while(k<nums.size() and nums[j]==nums[k])k++;
                j=k-1;
                
                
            
        }
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        sort(arr.begin(),arr.end());
        vector<int>visited(n,0);
        vector<int>cur;
        backtrack(arr,0,cur);
        return lans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends