class Solution {
public:
  
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int n = heights.size();
        int ans = 0;
        for(int i = 0 ; i < n ;i++){
            int cur = heights[i];
            while(!st.empty() and heights[st.top()] > cur){
                int right = i;
                int curt = heights[st.top()];
                st.pop();
                int left = -1;
                if(!st.empty()){
                    left = st.top();
                }
                ans = max(ans , (right - left - 1 ) * curt);
            }
            st.push(i);
        }
        return ans;
            
    }
};