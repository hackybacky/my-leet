class Solution {
public:
    int n;
    int binary_search(vector<int>&a,int l,int r){
        if(l<0 or r>=n or l>r){
            return -1;
        }
        
        int mid=(l+r)/2;
        if(a[l]<=a[r])return a[l];
        if(mid-1>=0 and mid+1<n and a[mid]<a[mid-1] and a[mid]<a[mid+1]){
            return a[mid];
            
        }
        
        if(a[mid]>a[r])return binary_search(a,mid+1,r);
        else return binary_search(a,l,mid-1);
    }
    int findMin(vector<int>& nums) {
        n=nums.size();
        
        return binary_search(nums,0,n-1);
        
        
    }
};