class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cur = 1;
        int carry=0;
        int n = digits.size();
        int i;
        for( i=n-1;i>=0;i--){
            
            cur = digits[i]+1;
            digits[i]=cur%10;
            if(cur<10)break;
            else cur=1;
            
        }
        if(i==-1){
            digits.push_back(1);
            reverse(digits.begin(),prev(digits.end()));
            reverse(digits.begin(),digits.end());
        }
        return digits;
    }
};