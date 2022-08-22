class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return 0;
        if(n==1)return 1;
        int set = __builtin_popcount(n);
        
        if(set>1)return 0;
        
        if(n==2)return false;
        
        if(n&(0b1010101010101010101010101010101))return true;
        
        return false;
    }
};