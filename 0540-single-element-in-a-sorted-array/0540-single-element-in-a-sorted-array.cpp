class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        
        int l = 0 , r = a.size()/2;
        if(a.size() % 2 == 1){
            r--;
        }
        while(l <= r){
            int mid = (l + r)/2;
            if(a[2*mid] != a[2*mid + 1]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return a[2 * l];
    }
};