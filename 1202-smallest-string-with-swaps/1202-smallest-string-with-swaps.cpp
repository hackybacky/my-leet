class Solution {
public:
    vector<int> parent;
   vector<long long int >size;
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        parent.assign(s.size(),0);
        size.assign(s.size(),0);
        for(int i=0;i<s.size();i++)parent[i]=i,size[i]=i;
        for(auto it : pairs){
            unify(it[0],it[1]);
        }
        map<int,vector<int>>mp;
        for(int i=0; i<s.size(); i++){
            int p = get(i);
            mp[p].push_back(i);
        }
        for(auto it : mp){
            auto v = it.second;
            string ss="";
            for(auto it2 : v)ss+=s[it2];
            sort(ss.begin(),ss.end());
            for(int j=0; j<v.size();j++){
                s[v[j]]=ss[j];
            }
        }
        
        return s;
    }
};