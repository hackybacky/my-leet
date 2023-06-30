//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
      // Code here
      double ans = 0;
      double l = 0.0000000001 , r = 1e9;
      while( (r - l) > (1e-9)){
          double mid = (l + r )/ 2.0;
          int add = 0;
          for(int i = 1 ; i < stations.size() ; i++){
              if(stations[i] - stations[i - 1] > mid){
                //   cout << "hello" << " " << mid <<  endl;
                  int d = ceil((stations[i] - stations[i - 1] )/(mid));
                //   cout <<d << endl;
                  add += (d - 1);
                  
              }
          }
          if(add <= K){
              r = mid;
              ans = mid;
            //   cout << "hello" <<" "<< add << endl;
          }
          else {
              l = mid;
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends