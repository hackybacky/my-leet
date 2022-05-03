class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i=0;
        
        while(i<nums.size()-1 and nums[i]<=nums[i+1])i++;
       // i--;
        int n = nums.size()-1;
        int j= n ;
            
        while(j>=1 and nums[j-1]<=nums[j])j--;
       // j++;
        if(j>i){
            int mini = INT_MAX,maxi = INT_MIN;
            for(int k=i;k<=j; k++){
                mini=min(mini,nums[k]);
                maxi= max(maxi,nums[k]);
            }
            
            int k=0;
            while(k<nums.size() and nums[k]<=mini)k++;
            int start = k;
            int end;
            k=n;
            while(k>=0 and nums[k]>=maxi)k--;
            end=k;
            cout<<end<<" "<<start<<" "<<maxi<<" "<<mini<<endl;
            return end-start+1;
        }
        return 0;
    }
};