class Solution {
public:
    vector<int> parent;
    vector<int> gn;
    
    int create_mask(string s){
        int mask=0;
        for(auto it :s ){
            mask |=(1<<(it-'a'));
           // cout<<mask<<endl;
        }
    
        return mask;
    }
    
    int find(int p) {
        if (parent[p] == -1) return p;
        parent[p] = find(parent[p]);
        return parent[p];
    }
    
    int un(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return pa;
        parent[pb] = pa;
        //cout<<"jkklf"<<endl;
        
        gn[pa] += gn[pb];
        return pa;
    }
    
    vector<int> groupStrings(vector<string>& words) {
        int n=words.size();
        gn.assign(n+11,1);
        parent.assign(n+11,-1);
        unordered_map<int,int>mp;
        int j=1;
        
        for(auto it : words){
            
            int mask=create_mask(it);
            
            if(mp[mask]==0)
            mp[mask]=j;
            else{
                un(j,mp[mask]);
            }
            for(int i=0; i<=26;i++){
                int d=( (1<<i));
                if(!(mask&d))continue;
                int cur=mp[(mask ^ d)];
                int e=mask^d;
                
                if(cur >0 ){
                  
                    un(j,cur);
                }
               if(mp[e]==0)mp[e]=j;
               
            }
            j++;
            
        }
       
        int group=0;
        set<int>s;
        int ans=0;
        
        for(int i=1; i<=n;i++){
            int par=find(i);
            ans=max(ans,gn[par]);
           // cout<<i <<" "<<par<<endl;
            s.insert(par);
        }
       // for(auto it : gn)cout<<it<<" ";
        group=s.size();
        return {{group,ans}};
        
        
    }
};