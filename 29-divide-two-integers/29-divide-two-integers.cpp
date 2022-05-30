class Solution {
public:
//         int divide(int A, int B) {
//         if (A == INT_MIN && B == -1) return INT_MAX;
        
//         int a = abs(A), b = abs(B), res = 0;
//         for (int x = 31; x >= 0; x--)
//             if ((signed)((unsigned)a >> x) - b >= 0)
//                 res += 1 << x, a -= b << x;
//         return (A > 0) == (B > 0) ? res : -res;
//     }
    int divide(int dividend, int divisor) {
       
        // dividend=dividend>>1;
        if(dividend==INT_MIN and divisor==-1)return INT_MAX;
        if(divisor==(1))return dividend;
        if(divisor==-1)return -dividend;
        if(divisor==INT_MIN){
            return (dividend==INT_MIN?1:0);
        }
        if(dividend==INT_MIN){
            return divisor > 0 ? divide(dividend + divisor, divisor) - 1 : divide(dividend - divisor,                   divisor) +1;
        }    
        
        
        int a = abs(dividend);
         int b = abs(divisor);
        int res=0;
        for(int i=31;i>=0; i--){
            if((a>>i)>=b){
                res+=(1<<i);
                a-=(b<<i);
            }
        }
        if(divisor <0 and dividend<0)return res;
        return (dividend<0 or divisor<0)?-res:res;
        
    }
};