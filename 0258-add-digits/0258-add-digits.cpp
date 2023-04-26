class Solution {
public:
    int sumDigit(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    int addDigits(int num) {
        
        while(to_string(num).size() > 1){
            num = sumDigit(num);
        }
        return num;
        
    }
};