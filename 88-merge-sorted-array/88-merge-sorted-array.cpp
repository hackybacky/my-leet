class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
       vector<int>ans;
        int l=0,r=0;
        for(int i=0; i<m+n;i++){
            if(l==m)ans.push_back(nums2[r]),r++;
            else if(r==n)ans.push_back(nums1[l]),l++;
            else if(nums1[l]<nums2[r])ans.push_back(nums1[l]),l++;
            else ans.push_back(nums2[r]),r++;
            
        }
        nums1=ans;
    }
};