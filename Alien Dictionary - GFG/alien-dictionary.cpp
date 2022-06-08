// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here 
        
        map<char,vector<int>> graph;
        map<char,int>indeg;
        for(int i=1 ;  i<N  ; i++){
            int len =min(dict[i].size(),dict[i-1].size());
            for(int j=0 ; j< len ; j++){
                if(dict[i-1][j]!=dict[i][j]){
                    
                    graph[dict[i-1][j]].push_back(dict[i][j]);
                    indeg[dict[i][j]]++;
                    break;
                    // cout<<"lj"<<endl;
                }
            }
        }
        queue<char>q;
        for(int i=0; i<K;i++){
            char c  = 'a'+i;
            
            if(indeg[c]==0){q.push(c);}
        }
        string ans="";
        while(!q.empty()){
            char f= q.front();
            q.pop();
            // cout<<f<<endl;
            ans+=f;
            for(auto it :graph[f]){
                
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
    //   / cout<<ans<<endl;
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends