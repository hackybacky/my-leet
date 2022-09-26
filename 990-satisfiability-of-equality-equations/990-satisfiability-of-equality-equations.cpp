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
             //remove size line for directed graph or tree means next two lines 
            if (size[x] < size[y]) swap(x, y);
                size[x]+=size[y];
            parent[y] = x;

        }
    };
    bool equationsPossible(vector<string>& equations) {
        
        int n = equations.size();
        DSU<26> dsu;
        vector<string>eq , neq;
        for(auto it : equations){
            if(it[1] == '!')
                neq.push_back(it);
            else 
                eq.push_back(it);
        }
        for(auto it : neq)
            eq.push_back(it);
        for(auto it : eq){
            int a = (it[0] - 'a') , b = (it[3]-'a');
            if(it[1] == '='){
                dsu.unify(a , b);
            }
            else{
                int pa = dsu.get(a) , pb = dsu.get(b);
                if(pa == pb){
                    return false;
                }
            }
        }
        return true;
        
        
    }
};