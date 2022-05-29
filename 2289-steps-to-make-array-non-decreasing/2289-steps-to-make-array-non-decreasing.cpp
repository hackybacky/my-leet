class Solution {
public:
    int totalSteps(vector<int>& nums) {
        
        stack<pair<int,int>>st;
        int l=0;
        int n = nums.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(st.empty())st.push({nums[i],0});
            else{
                
                if(st.top().first<nums[i]){
                    int cur=0;
                    while(!st.empty() and st.top().first<nums[i]){
                        cur = max(cur+1,st.top().second);
                        st.pop();
                        ans=max(ans,cur);
                        
                    }
                    // cout<<cur<<endl;
                    l=max(l,cur);
                    st.push({nums[i],cur});
                }
                else st.push({nums[i],0});
            }
        }
        // for(auto it:ans)cout<
        return ans;
        
    }
};