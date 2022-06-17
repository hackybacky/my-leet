class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int>st;
        stack<int>as;
        
        int s_length=s.size();
        
        for(int i=0 ; i< s_length;i++){
            if(s[i]=='('){cout<<"dsfs";st.push(i);}
            else if(s[i]=='*')as.push(i);
            else{
                if(!st.empty())st.pop();
                else if(!as.empty())as.pop();
                else return false;
            }
        }
        
        while(!st.empty()){
            
            if(as.empty())return false;
            
            if(st.top()>as.top())return false;
            st.pop(),as.pop();
        }
        return true;
    }
};