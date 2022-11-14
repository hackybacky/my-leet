class Solution {
public:
    
    unordered_map<int , int > parent;
    // unordered_map<int , int > siz;
    int islands ;
    int get(int v){
        if(parent.find(v) == parent.end()){
            islands++;
            return parent[v] = v;
        }
        if(parent[v] == v){
            return v;
        }
        
        return parent[v] = get(parent[v]);
    }
    
    void unify(int u , int v){
        int pa = get(u) , pb = get(v);
        
        if(pa != pb){
            parent[pa] = pb;
            islands--;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        
        for(auto it : stones){
            unify(it[0] , it[1] + 10001);
        }
        return stones.size() - islands;
    }
};