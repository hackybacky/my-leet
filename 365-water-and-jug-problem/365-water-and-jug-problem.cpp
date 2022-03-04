class Solution {
public:
    
    bool canMeasureWater(int a, int b, int c) {
        if( a+b<c)return  false;
        
        int g =__gcd(a,b);
        
        if(c%g==0)return true;
        if(c==0)return true;
        
        return false;
    }
};