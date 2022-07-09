class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>d;
        d.push_back(0);
        for(int i=1;i<n;i++){
            
            if(d.front()<i-k)d.pop_front();
            
            int cur = nums[i]+nums[d.front()];
            while(!d.empty() and cur>=nums[d.back()])d.pop_back();
            d.push_back(i);
            nums[i]=cur;
        }
        return nums[n-1];
    }
};