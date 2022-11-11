class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left =1;
        int right = 1;
        int n = nums.size();
        
        while(right<n){
            
            if( nums[right]==nums[right-1]){
                // cout<<"hello"<<endl;
            }
            else{
                cout<<left<<endl;
                nums[left]=nums[right];
                left++;
            }
            right++;
        }
        cout<<left<<endl;
        return left;
    }
};