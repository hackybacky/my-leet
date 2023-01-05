class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        
        vector<int>ans;
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            
            int cur = nums[i];
            while(!dq.empty() and nums[dq.back()] <= cur){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i == k - 1){
                ans.push_back(nums[dq.front()]);
            }
            else if(i >= k){
                int req = i - k;
                while(!dq.empty() and dq.front() <= req){
                    dq.pop_front();
                }
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
        
    }
};