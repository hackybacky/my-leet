class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetlen) {
        sort(tiles.begin(),tiles.end());
        int n = tiles.size();
        int ans = 0;
        vector<int>pref(n+1,0);
        auto p = pref;
        
        for(int i=0; i<n; i++)p[i]=tiles[i][1];
        
        for(int i=0; i< n ; i++ ){
            pref[i]+=(i-1>=0?pref[i-1]:0)+(tiles[i][1]-tiles[i][0]+1);
            auto it = lower_bound(p.begin(),p.begin()+i,max(0,tiles[i][1]-carpetlen+1));
            
            auto indi = it-p.begin();
        
            int prev=max(0,(tiles[i][1]-carpetlen+1)-tiles[indi][0]);
        
            if(indi-1>=0){
                prev+=pref[indi-1];
            }
           
            ans=max(ans,pref[i]-prev);
            
        }
        return ans;
    }
};