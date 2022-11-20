class Solution {
public:
//     int calculate(string s) {
//     int total = 0;
//     vector<int> signs(2, 1);
//     for (int i=0; i<s.size(); i++) {
//         char c = s[i];
//         if (c >= '0') {
//             int number = 0;
//             while (i < s.size()  &&  s[i] >= '0')
//                 number = 10 * number + s[i++] - '0';
//             total += signs.back() * number;
//             signs.pop_back();
//             i--;
//         }
//         else if (c == ')')
//             signs.pop_back();
//         else if (c != ' ')
           
//             signs.push_back(signs.back() * (c == '-' ? -1 : 1));
//     }
//     return total;
// }
    int calculate(string s) {
        
        stack<int> st;
        int num = 0 ;
        int sign = 1;
        int res = 0;
        int n = s.size();
        for(int i = 0 ;i < n ;i++){
            if(s[i] >= '0'){
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '+'){
                res += sign * num;
                sign = 1;
                num = 0;
            }
            else if(s[i] == '-'){
                res += sign * num ;
                sign = -1;
                num = 0;
            }
            else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                sign = 1;
                res = 0;
            }
            else if(s[i] == ')' ){
                res += sign * num;
                num = 0;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        if(num){
            res += sign * num;
        }
        return res;
    }
};