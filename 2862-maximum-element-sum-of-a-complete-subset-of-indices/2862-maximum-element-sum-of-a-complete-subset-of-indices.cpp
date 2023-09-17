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
    long long maximumSum(vector<int>& nums) {
        
        int n = nums.size();
        DSU<10001> dsu;
        long long mx = 0;
        for(int i = 1 ; i <= n ; i++){
            // mx = max(mx , (long long)nums[i - 1] * 2ll);
            for(int j = 1 ; j * j <= i;  j++){
                int d = i * i;
                if(i % j != 0){
                    continue;
                }
                
                // cout << j << " "<< i << endl;
                int f = i / j;
                int f2 = j;
                int g = d / f;
                int g2 = d / f2;
                if(f <= n and g <= n and f != g)dsu.unify(f , g);
                if(f2 <= n and g2 <= n and f2 != g2){dsu.unify(f2 , g2);}
            }
        }
        
        map<int , long long > mp;
        for(int i = 1 ; i <= n ; i++){
            int pa = dsu.get(i);
            mp[pa] += nums[i - 1];
            
        }
        
        long long maxi = 0;
        for(auto it : mp)maxi = max(maxi , it.second);
        return maxi;
    }
};