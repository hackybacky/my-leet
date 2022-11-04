//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        int curleft = 0 , curright = n - 1;
        int leftmost = 0 , rightmost = 0;
        long long ans = 0;
        while(curleft < curright){
            
            if(arr[curleft] < arr[curright]){
                if(arr[curleft] >= leftmost){
                    leftmost = arr[curleft];
                }
                else{
                    ans += leftmost - arr[curleft];
                }
                curleft++;
            }
            else{
                if(arr[curright] >= rightmost){
                    rightmost = arr[curright];
                }
                else{
                    ans += rightmost - arr[curright];
                }
                curright--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends