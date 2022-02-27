class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k,j=k;
        int n=nums.size();
        int ans=nums[k];
        int mini=nums[k];
        while((i>0 or j<n-1) and(i<=j) ){
            int di=-1,dj=di;
            if(i-1>=0){
                di =nums[i-1];
                
                ans=max(ans,(j-i+2)*min(di,mini));
            }
            if(j+1<n){dj=nums[j+1];
                ans=max(ans,(j-i+2)*min(dj,mini));}
            if(di>=dj and di!=-1){
                
                i--;
                mini=min(mini,di);
            }
            else if(dj!=-1){
                mini=min(mini,dj);
                j++;
            }
            else break;
           // cout<<di<<" "<<dj<<" "<<mini<<endl;
        }
        return ans;
    }
};