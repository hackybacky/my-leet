class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        if(n==1)return a[0];
        int l = 0 , r = n-1;
        int ans=-1;
        while(l<=r){
            int mid = (l+r)/2;
            bool o=false,f=false;
            if(mid%2==1)o=true;
            bool flag=true;
            if(mid+1<n and a[mid]==a[mid+1])flag=false;
            if(mid-1>=0 and a[mid]==a[mid-1])flag=false;
            if(flag)return a[mid];
            if(o){
                if(mid-1>=0 and a[mid]==a[mid-1])l=mid+2;
                else r=mid-1;
            }
            else {
                if(mid+1<n and a[mid]==a[mid+1])l=mid+2;
                else r=mid-2;
            }
           
        }
        
        return a[l-1];
    }
};