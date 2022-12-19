//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        queue<pair<int , int >> pq;
        
        vector<vector<pair<int , int >>> graph(n + 1);
        for(auto it : flights){
            int u = it[0] , v = it[1]  , w = it[2];
            graph[u].push_back({v , w});
            // graph[v].push_back({u , w});
        }
        pq.push({0 , k});
        vector<int>dis(n + 1 , INT_MAX);
        dis[k] = 0;
        int ans = 0;
        while(!pq.empty()){
            auto f = pq.front();
            int node = f.second;
            int curd = f.first;
            pq.pop();
            
            for(auto it : graph[node]){
                int nd = curd + it.second;
                int nwnode = it.first;
                if(dis[nwnode] > nd){
                    dis[nwnode] = nd;
                    pq.push({nd , nwnode});
                }
            }
        }
        for(int i = 1 ;i <= n ;i++){
            // cout << dis[i] << " node " << i << endl;
            if(dis[i] == INT_MAX)return -1;
            ans = max(ans , dis[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends