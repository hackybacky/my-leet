// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++
#include<bits/stdc++.h>
class Solution {
public:
    struct Node{
      int d,id , t;  
    };
    struct CompareHeight {
    bool operator()(Node const& p1, Node const& p2)
    {
       
        return p1.d < p2.d or (p1.d==p2.d and p1.t<p2.t) or (p1.d==p2.d and p1.t==p2.t and p1.id>p2.id);
    }
};
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
        
        priority_queue<Node , vector<Node>, CompareHeight>pq;
        int taken=n;
        for(int i=0; i<n; i++){
            struct Node n;
            n.d=arr1[i];
            n.id=i;
            n.t=1;
            struct Node n2;
            n2.d=arr2[i];
            n2.id= i;
            n2.t=2;
            pq.push(n);
            pq.push(n2);
            
        }
        vector<pair<int,int>>ans1,ans2;
        map<int,bool> v;
        while(taken>0 and !pq.empty()){
            auto t = pq.top();
            pq.pop();
            auto d = t.d;
            if(v[d])continue;
           // cout<<d<<endl;
            v[d]=true;
            if(t.t==1){
                ans1.push_back({t.id,d});
            }
            else ans2.push_back({t.id,d});
            taken--;
        }
        sort(ans1.begin(),ans1.end());
        vector<int>ans;
        sort(ans2.begin(),ans2.end());
        for(int i=0; i<ans2.size(); i++){
            ans.push_back(arr2[ans2[i].first]);
            //cout<< (arr2[ans2[i].first]) << endl;
        }
        for(int i=0; i<ans1.size(); i++){
            ans.push_back(arr1[ans1[i].first]);
            //cout<<(ans1[i].first)<<endl;
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends