class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int>st;
        int n = asteroids.size();
        vector<int>neg;
        for(auto it : asteroids){
            if(it > 0)st.push(it);
            else{
                while(!st.empty() and st.top() < -it){
                
                    st.pop();
                }
                if(st.empty() or st.top() < -it ){
                    neg.push_back(it);
                }
                if(!st.empty() and st.top() == -it)st.pop();
                // if(!st.empty())
            }
        }
        vector<int>ans;
        for(int i = 0 ; i < neg.size() ; i++)ans.push_back(neg[i]);
        stack<int>s;
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        while(!s.empty())ans.push_back(s.top()) , s.pop();
        return ans;
    }
};