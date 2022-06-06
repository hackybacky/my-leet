class Solution {
public:
    vector<int>parent,size;
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
    void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
  int minCostConnectPoints(vector<vector<int>>& ps) {
    
        priority_queue<pair<int,pair<int,int>>>pq;
      
        int n= ps.size();
      parent.assign(n+1,0);
      size=parent;
      for(int i=0; i<n; i++)parent[i]=i,size[i]=1;
      for(int i=0 ; i<n; i++){
          for(int j=i+1;j<n;j++){
              int d = abs(ps[i][0]-ps[j][0])+abs(ps[i][1]-ps[j][1]);
              pq.push({-d,{i,j}});
          }
      }
      int ans=0;
      while(!pq.empty()){
          auto t = pq.top();
          pq.pop();
          int d = -t.first;
          int x = t.second.first;
          int y = t.second.second;
          
          int px = find_set(x),py=find_set(y);
          if(px!=py){
              union_sets(x,y);
              ans+=d;
          }
          
      }
      return ans;
    }
};