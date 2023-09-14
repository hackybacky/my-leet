class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        deque<int>st;
        int n = asteroids.size();
    
        vector<int>ans;
        for(auto it : asteroids){
            if(it > 0)st.push_back(it);
            else{
                while(!st.empty() and st.back() < -it){
                    st.pop_back();
                }
                if(st.empty()  ){
                    ans.push_back(it);
                }
                if(!st.empty() and st.back() == -it)st.pop_back();
            }
        }
        while(!st.empty()){
            ans.push_back(st.front());
            st.pop_front();
        }
        return ans;
    }
};