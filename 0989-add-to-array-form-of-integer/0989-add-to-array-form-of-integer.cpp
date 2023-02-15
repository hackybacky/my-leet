class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i = n - 1;
        int carry = 0;
        while(k or i >= 0){
            int rem = k % 10;
            if(i >= 0){
                int current = num[i] + rem + carry;
                num[i] = current % 10;
                carry = current / 10;
            }
            else{
                int current = carry + rem;
                num.insert(num.begin() , current % 10);
                carry = current / 10;
            }
            i--;
            k /= 10;
        }
        if(carry){
            num.insert(num.begin(), carry);
        }
        return num;
        
    }
};