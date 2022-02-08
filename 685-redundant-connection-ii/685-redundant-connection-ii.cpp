class Solution {
public:
    
   template<int SZ> struct DSU {
    int parent[SZ], size[SZ];
 int i;
    DSU() {
        for(int i=0; i< SZ; i++) parent[i] = i, size[i] = 1;
    }
 
    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }
 
    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        // f (size[x] < sizie[y]) swap(x, y);
        //     size[x]+=size[y];
        parent[y] = x;
 
    }
};

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int first=-1,second=-1;
        int n=edges.size();
        vector<int> par(n+1,-1);
        DSU<1001> dsu;
        
        int last=-1;
        for(int i=0; i<n ; i++){
            int p=edges[i][0],c=edges[i][1];
            if( par[c]!=-1  ){
                first = par[c];
                second=i;
                continue;
            }
            par[c]=i;
            int pa= dsu.get(p);
            if(pa==c){
                last=i;
            }
            else dsu.unify(p,c);
                
        }
        cout<<first<<endl;
        if(last==-1)return edges[second];
        if(second==-1)return edges[last];
        return edges[first];
        
        
    }
};