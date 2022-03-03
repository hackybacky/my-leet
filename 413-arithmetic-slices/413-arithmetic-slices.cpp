class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        nums.push_back(-1);
        int n=nums.size();
        int i=2;
        int pred= nums[1]-nums[0];
        int j=0;
        while(i<n){
            if(nums[i]-nums[i-1]!=pred){
                int toadd = (i-j-2);
                if(toadd>=0)
                    ans+=(toadd*(toadd+1)/2);
                
                j=i-1;
                pred= nums[i]-nums[i-1];
            }
            i++;
        }
        return ans;
    }
};