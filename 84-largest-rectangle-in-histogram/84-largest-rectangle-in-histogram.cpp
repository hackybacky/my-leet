class Solution {
public:
    auto  next_smaller(vector<int> &a){
    int n=a.size();
    stack<pair<int,int>> st;
    vector<int> ng(n+1,n);

    for(int i=0;i<n; i++){

        int next=a[i];
        if(st.empty()){
            st.push({a[i],i});
            continue;
        }

        while(!st.empty() and st.top().first > next ){
            ng[st.top().second]=i;
            st.pop();

        }

        st.push({next,i});
    }

    return ng;

    
}   
     auto  next_smaller2(vector<int> &a){
    int n=a.size();
    stack<pair<int,int>> st;
    vector<int> ng(n+1,-1);

    for(int i=n-1;i>=0; i--){

        int next=a[i];
        if(st.empty()){
            st.push({a[i],i});
            continue;
        }

        while(!st.empty() and st.top().first > next ){
            ng[st.top().second]=i;
            st.pop();

        }

        st.push({next,i});
    }

    return ng;

    
}
    int largestRectangleArea(vector<int>& heights) {
        auto v = next_smaller(heights);
        auto pv = next_smaller2(heights);
        int ans =0;
        int n = heights.size();
        for(int i=0;i<n ;i++){
            auto indi = v[i];
            int len = indi-i;
            len =len+i-(pv[i]);
            len-=1;
            ans = max(ans,len*heights[i]);
        }
        return ans;
    }
};