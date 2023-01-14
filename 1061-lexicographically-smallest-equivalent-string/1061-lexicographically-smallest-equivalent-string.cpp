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
  	        if (x > y) swap(x, y);
  	        size[x]+=size[y];
  	        parent[y] = x;
  	 
  	    }
  	};
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        DSU<26> dsu;
        int n = s1.size();
        for(int i = 0 ; i < n ;i++){
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            dsu.unify(a , b);
        }
        string ans = "";
        for(int i = 0 ; i < baseStr.size() ; i++){
            int cur = baseStr[i] - 'a';
            int par = dsu.get(cur);
            ans += char('a' + par);
        }
        return ans;
    }
};