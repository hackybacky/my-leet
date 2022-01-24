class Solution {
public:
    int countTriplets(vector<int>& nums) {
        
        map<int,int> cnt;
        int n=nums.size();
        //map<int,int> occ;
        for(int i= 0; i<n; i++){
            for(int j=0 ; j< n ; j++){
                cnt[nums[i]&nums[j]]++;
            }
           // occ[nums[i]]++;
        }
        
        int ans=0;
        
        for(int i=0; i<n ; i++){
            int b=nums[i];
            int bit=((1<<16)-1)-b;
            for(int j=bit ; j>=1; j=(j-1)&bit){
                if(cnt[j])ans+=cnt[j];
                
            }
            ans+=cnt[0];
            
        }
        return ans;
    }
};