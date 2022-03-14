class Solution {
public:
    bool isValid(string s) {
        
        stack<char> s_stack;
        
        for(auto it : s){
            if(it=='(' or it=='{' or it=='['){
                s_stack.push(it);
            }
            else {
                if(s_stack.empty())return false;
                if(it==')' and s_stack.top()!='(')return false;
                else if(it=='}' and s_stack.top()!='{')return false;
                else if(it==']' and s_stack.top()!='[')return false;
                s_stack.pop();
            }
        }
        if(!s_stack.empty())return false;
        return true;
        
    }
};