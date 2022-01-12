class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        
        int l=0,r=200;
        int n=v.size();
        while(l<=r){
            int mid=(l+r)/2;
            set<string > s;
            for(int i= 0 ; i<n ;i++ ){
                s.insert(v[i].substr(0,mid));
            }
            if(s.size()==1){
                l=mid+1;
            }
            else r=mid-1;
        }
        
        return v[0].substr(0,l-1);
        
    }
};