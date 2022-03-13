class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n==1 ){
            if(k%2==0)return nums[0];
            else return -1;
            
        }
        
        if(k<n ){
            int maxi = (k<n ? nums[k]:0);
            for(int i=0; i<k-1;i++){
                maxi=max(maxi,nums[i]);
            }
            return maxi;
        }
        else if(k==n){
            return *max_element(nums.begin(),nums.begin()+n-1);
        }
        else if(k>n){
            return *max_element(nums.begin() , nums.end());
        }
        return 0;
        
    }
};