class Solution {
public:
    int jump(vector<int>& nums) {
        
        int cur = 0;
        int fat=-1;
        int ans=0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            fat=max(fat,i+nums[i]);
            fat=min(n-1,fat);
            if(i==cur){
                ans++;
                cur=fat;
                
            }
        }
        return ans-1;
    }
};