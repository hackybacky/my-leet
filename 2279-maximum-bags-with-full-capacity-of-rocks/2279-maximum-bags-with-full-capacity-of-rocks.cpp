class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        
        return abs(a.first-a.second)<abs(b.first-b.second);
    }
    int maximumBags(vector<int>& c, vector<int>& r, int ad) {
        vector<pair<int,int>>vp;
        
        for(int i =0; i<r.size(); i++){
            vp.push_back({c[i],r[i]});
            
        }
        sort(vp.begin(),vp.end(),cmp);
        
        int ans=0;
        for(int i=0; i<r.size(); i++){
            // cout<<vp[i].first<<" "<<vp[i].second<<endl;
            // if(vp[i].first==vp[i].second)continue;
            if(vp[i].first-vp[i].second<=ad){
                ans++;
                ad-=(vp[i].first-vp[i].second);
            }
        }
        return ans;
    }
};