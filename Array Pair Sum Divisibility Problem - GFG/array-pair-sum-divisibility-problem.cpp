//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool canPair(vector<int> nums, int k) {
        int cnt = 0, n = nums.size(), start = 0, end = n-1;
        for(auto &i:nums)
            if(i%k == 0)cnt++, i = 0;
            else i = i%k;
        if(cnt%2!=0)return false;
        sort(nums.begin(), nums.end());
        start = cnt;
        while(start <= end){
            if(nums[start] + nums[end] == k)
                start++, end--;
            else
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends