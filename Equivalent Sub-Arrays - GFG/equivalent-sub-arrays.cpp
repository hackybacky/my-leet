// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int a[], int n)
    {
        //code here.
        unordered_map<int,bool>mp;
        
        for(int i=0;i<n;i++)mp[a[i]]=true;
        int dis= mp.size();
        
        unordered_map<int,int>cnt;
        int ans=0;
        int i=0,j=0;
        while(j<n){
            if(cnt[a[j]]==0){
                dis--;
                cnt[a[j]]++;
            }
            else cnt[a[j]]++;
            if(dis==0){
                ans+=n-j;
                
                while(dis==0){
                    cnt[a[i]]--;
                    if(cnt[a[i]]==0)dis++;
                    i++;
                    if(dis!=0)break;
                    ans+=n-j;
                }
            }
            j++;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends