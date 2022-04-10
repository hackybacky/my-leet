class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int>st;
        
        for(auto it : ops){
            if(it=="C"){
                st.pop();
            }
            else if(it=="D"){
                st.push(st.top()*2);
            }
            else if(it=="+"){
                int f= st.top();
                st.pop();
                int cur = f+st.top();
                st.push(f);
                st.push(cur);
            }
            else{
                st.push(stoi(it));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};