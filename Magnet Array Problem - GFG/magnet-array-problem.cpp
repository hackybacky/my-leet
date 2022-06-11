// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        void nullPoints(int n, double mag[], double getAnswer[])
    {
        // Your code goes here   
        cout<<fixed<<setprecision(12);
        for(int i=0  ; i<n-1; i++){
            double l = mag[i];
            double r = mag[i+1];
            int k = 20;
            double ans;
            while(k--){
                double mid = (l*1.0+r*1.0)/2.0 ;
                // cout<<mid<<endl;
                double left =0.0;
                int cur = i;
               
                while(cur>=0){
                    left+=(1.0/(mid-mag[cur]));
                    cur--;
                }
                cur=i+1;
               
                double right=0.0;
                while(cur<n){
                    right+=(1.0/(mag[cur]-mid));
                    
                    cur++;
                }
                if(left<=right){
                    ans=mid;
                    r=mid;
                }
                else l=mid;
            }
            getAnswer[i]=ans;
        }
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
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends