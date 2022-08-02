class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = -1e9 , r= 1e9;
        int ans=-1;
        int  n = matrix.size();
        
        while(l<=r){
            int mid =(l+r)/2;
            int cnt=0;
            for(int i=0;i<n; i++){
                auto it = upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
                cnt+=it;
            }
            
            if(cnt>=k)r=mid-1,ans=mid;
            else l=mid+1;
        }
        return ans;
    }
};