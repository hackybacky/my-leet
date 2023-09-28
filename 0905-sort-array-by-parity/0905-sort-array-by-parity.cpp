class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        
        int n = a.size();
        int j=0;
        for(int i=0; i<n; i++){
            if(a[i]%2==0){
                while(j<i and a[j]%2==0){
                    j++;
                }
                if(j<n)swap(a[i],a[j]);
            }
        }
        return a;
    }
};