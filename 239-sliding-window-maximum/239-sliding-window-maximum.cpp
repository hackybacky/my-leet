class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i =0 ; i< n ; i++ ){
            if(!dq.empty() and dq.front()==i-k)dq.pop_front();
            
            while(!dq.empty() and nums[dq.back()]<nums[i])dq.pop_back();
            
            dq.push_back(i);
            
            ans[i]=nums[dq.front()];
        }
        return vector<int>(ans.begin()+k-1,ans.end());
    }
};