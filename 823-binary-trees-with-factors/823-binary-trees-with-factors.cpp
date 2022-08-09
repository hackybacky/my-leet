class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        map<int,int>mp;
        sort(arr.begin(),arr.end());
        mp[arr[0]]=1;
        int  n = arr.size();
        int mod = 1e9+7;
        for(int i=1;i<n;i++){
            int cur_ele = arr[i];
            mp[cur_ele]=1;
            for(int j=0;j<i;j++){
                if(cur_ele%arr[j]!=0)continue;
                int ot = cur_ele/arr[j];
                auto it = lower_bound(arr.begin(),arr.begin()+i,ot);
                if(it==arr.begin()+i or *it!=ot)continue;
                // if(it!=arr.begin()+i){
                // cout<<arr[j]<<" "<< ot <<endl;
                int d = ((long long)mp[arr[j]]*(long long)mp[ot])%mod;
                mp[cur_ele] = (mp[cur_ele]+d)%mod;
                // if(ot!=arr[j])mp[cur_ele]=(mp[cur_ele]+2*d)%mod;
                // }
                
            }
        }
        int ans =0;
        for(auto it : mp){
            ans=(ans+it.second)%mod;
            // cout<<it.first<< " "<<it.second<<endl;
        }
        return ans;
    }
};