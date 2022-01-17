class Solution {
public:
    int find_point(vector<int> nums, int target,int l ,int r){
        
        if(l>r)return 0;
        
        int mid=(l+r)/2;
        if(mid+1< nums.size() and nums[mid] >nums[mid+1]){
            return mid+1;
        }
        // if( mid-1>=0 and nums[mid]<nums[mid-1])return mid;
        
        return max(find_point(nums,target,l,mid-1),find_point(nums,target,mid+1,r));
        
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
       
        int l=0,r=n-1;
        int indi=find_point(nums,target,0,n-1);
        auto it =lower_bound(nums.begin(),nums.begin()+indi,target);
        auto it2=lower_bound(nums.begin()+indi,nums.end(),target);
        cout<<indi<<endl;
        if(it!=nums.end() and *it==target){
            return it-nums.begin();
        }
        if(it2!=nums.end() and *it2==target)return it2-nums.begin();
        return -1;
    }
};