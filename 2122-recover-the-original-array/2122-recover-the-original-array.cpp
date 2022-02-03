class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
    
        int n=nums.size();
        
        vector<int> pk;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n; i++){
            if((nums[i]-nums[0])%2==0 )pk.push_back(nums[i]-nums[0]);
        }
        multiset<int> ss(nums.begin(),nums.end());
        vector<int> lans;
        int K;
        for(int i=0; i<pk.size(); i++){
            int k= pk[i];
            if(k%2==1 or k==0 )continue;
          //  cout<<k<<endl;
            auto s=ss;
            int sz=s.size();
            bool flag=true;
            vector<int> ans;
            while(!s.empty()){
                int f=*(s.begin());
                auto it = s.find(f+k);
                if(it==s.end()){
                    flag=false;break;
                }
                if( it!=s.end() ){
                    ans.push_back(f+k/2);
                    
                    
                    s.erase(it);
                    s.erase(s.begin());
                    sz-=2;
                }
                else {
                    flag=false;
                    break;
                }
            }
            if(flag)return ans;
            
        }
        return {};
    }
};