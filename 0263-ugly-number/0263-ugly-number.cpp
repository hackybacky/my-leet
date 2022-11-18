class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0){
            return 0;
        }
        vector<int> fact = {2 , 3 , 5};
        n = abs(n);
        for(int i = 0 ;i < 3 ; i++){
            int cur = fact[i];
            while(n % cur == 0 ){
                n /= cur;
            }
        }
        return n == 1;
        return true;
    }
};