class Solution {
public:
    int parent[26],size[26];
    
    int find(int v ){
        if(parent[v] == v)
            return v;
        return parent[v] = find(parent[v]);
    }
    void unify(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
         //remove size line for directed graph or tree means next two lines 
        if (size[x] < size[y]) swap(x, y);
        size[x]+=size[y];
        parent[y] = x;
 
    }
    bool equationsPossible(vector<string>& equations) {
        
        int n = equations.size();
        for(int i = 0 ; i < 26 ; i++)
            parent[i] = i , size[i] = 1;
        vector<string>eq , neq;
        for(auto it : equations){
            if(it[1] == '!')
                neq.push_back(it);
            else eq.push_back(it);
        }
        for(auto it : neq)
            eq.push_back(it);
        for(auto it : eq){
            int a = (it[0] - 'a') , b = (it[3]-'a');
            if(it[1] == '='){
                unify(a , b);
            }
            else{
                int pa = find(a) , pb = find(b);
                if(pa == pb){
                    return false;
                }
            }
        }
        return true;
        
        
    }
};