class TreeAncestor {
public:
    vector<vector<int>> fan;
    TreeAncestor(int n, vector<int>& parent) {
        
        fan.assign(n*2,vector<int>(30,-1));
        
        for(int i=0; i < n ; i++){
            fan[i][0]=parent[i];
        }
        
        for(int i=0; i<n; i++){
            for(int j=1; j<=20; j++){
                if(fan[i][j-1]==-1)break;
                fan[i][j]=fan[fan[i][j-1]][j-1];
            }
        }
       // cout<<fan[5][1];
        
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i=0; i<20 ; i++){
            if(k&(1<<i)){
                if(node<0)return -1;
                node = fan[node][i];
            }
        }
        return node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */