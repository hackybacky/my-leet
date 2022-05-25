class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[0]<b[0] or (a[0]==b[0] and a[1]>b[1] );
    }
    int maxEnvelopes(vector<vector<int>>& en) {
        int n = en.size();
        sort(en.begin(),en.end(),cmp);
        int lastx=0,lasty=0;
        vector<int>res;
        for(int i=0; i<n; i++){
            // cout<<en[i][0]<<" "<<en[i][1]<<endl;
            auto it = lower_bound(res.begin(),res.end(),en[i][1]);
            if(it==res.end())res.push_back(en[i][1]);
            else res[it-res.begin()] = en[i][1];
           
        }
        
        return res.size();
        
    }
};