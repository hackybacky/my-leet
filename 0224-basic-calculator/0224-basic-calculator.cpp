class Solution {
public:
    int calculate(string s) {
        
        stack<int>st;
        
        int num = 0 ;
        int res = 0 ;
        
        int sign = 1;
        int n = s.size();
        for(int i = 0 ; i < n ;i++){
            char c = s[i];
            if(c == ' ')continue;
            if( isdigit(c)){
                num = num * 10 + (s[i] - '0');
            }
            else if(c == '-'){
                res += sign * num;
                sign = -1;
                num = 0;
            }
            else if(c == '+'){
                res += sign * num;
                sign = 1 ;
                num = 0;
            }
            else if(c == '('){
                // res += sign * num;
                st.push(res);
                st.push(sign);
                sign = 1 ;
                res = 0;
            }
            else if(c == ')') {
                res += sign * num;
                res *= st.top();
                st.pop();
                res += st.top();
                cout << res << endl;
                st.pop();
                num = 0;
            }
        }
        if(num)res += num * sign;
        return res;
    }
};