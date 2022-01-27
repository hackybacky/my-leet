class Solution {
public:
    int n;
    int binary_search(vector<int>&a,int l,int r){
        
        if(l<0 or r>=n or l>r){
            return -1;
        }
        
        int mid=(l+r)/2;
        if(mid==0 and a[mid]>a[mid+1])return mid;
        if(mid==n-1 and a[mid-1]<a[mid])return mid;
        
        if(mid>=0 and mid<n and mid-1>=0 and mid+1<n and a[mid]>a[mid-1] and a[mid]>a[mid+1]){
            return mid;
        }
        
        return max(binary_search(a,l,mid-1),binary_search(a,mid+1,r));
        
    }
    int findPeakElement(vector<int>& nums) {
        
        n=nums.size();
        if(n==1)return 0;
        int ans=binary_search(nums,0,n-1);
        return ans;
        
    }
};