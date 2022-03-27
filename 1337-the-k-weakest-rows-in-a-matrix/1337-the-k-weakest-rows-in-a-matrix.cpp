class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        
        return (a.first<b.first) or ( a.first==b.first and a.second<b.second);
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> cur;
        for(int i=0; i<n ; i++){
            int l=0,r=m-1;
            
            while(l<=r){
                int mid =(l+r)/2;
                if(mat[i][mid]==0)r=mid-1;
                else l=mid+1;
            }
           // cout<<l<<endl;
            cur.push_back({l,i});
        }
        sort(cur.begin(),cur.end(),cmp);
        vector<int> p;
        for(int i=0; i<k ; i++){p.push_back(cur[i].second);}
        return p;
    }
};