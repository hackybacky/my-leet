// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	    struct query
{
  int l,r,i;
};


// const int BLOCK_SIZE=750;

static bool cmp(query p, query q) {
    const int BLOCK_SIZE=750;
    if (p.l / BLOCK_SIZE != q.l / BLOCK_SIZE)
        return p.l/BLOCK_SIZE < q.l/BLOCK_SIZE;
    return (p.l / BLOCK_SIZE & 1) ? (p.r < q.r) : (p.r > q.r);
}
	vector<int>SolveQueris(string s, vector<vector<int>>Query){
	    // Code here

        vector<query>vq;
        int i=0;
        for(auto it : Query){
            struct query q;
            q.l=it[0]-1;
            q.r=it[1]-1;
            q.i=i++;
            vq.push_back(q);
        }
        sort(vq.begin(),vq.end(),cmp);
        map<char,int>mp;
        vector<int>anss(Query.size());
        int cur_r=-1,cur_l=-1;
        for(auto q : vq){
            //cout<<q.l<<" "<<q.r<<endl;
            while (cur_l > q.l) {
                  cur_l--;
                  (mp[s[cur_l]])++;
              }
              while (cur_r < q.r) {
                  cur_r++;
                  mp[s[cur_r]]++;
              }
              while (cur_l < q.l) {
                  if(mp[s[cur_l]])
                  mp[s[cur_l]]--;
                  cur_l++;
              }
              while (cur_r > q.r) {
                  if(mp[s[cur_r]])
                  mp[s[cur_r]]--;
                  cur_r--;
              }
              int ans =0;
              for(auto it:mp){
                  if(it.second>0)ans++;
              }
              anss[q.i]=ans;
        }
        return anss;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends