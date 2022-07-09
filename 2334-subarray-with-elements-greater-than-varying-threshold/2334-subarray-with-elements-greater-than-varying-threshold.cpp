class Solution {
public:
    int validSubarraySize(vector<int>& a, int threshold) {
         stack<int>st;
        int n = a.size();
        vector<int>ns(n,n);
        for(int i=0;i<n;i++){
            int cur = a[i];
            
            while(!st.empty() and cur<a[st.top()]){
                ns[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        stack<int>stt;
        vector<int>ps(n,-1);
        for(int i=n-1;i>=0;i--){
            int cur = a[i];
            while(!stt.empty() and cur<a[stt.top()]){
                ps[stt.top()]=i;
                stt.pop();
            }
            stt.push(i);
        }
        
        for(int i=0;i<n;i++){
            int l = ps[i];
            int r = ns[i];
            int len = r-l-1;
            // if(len<)
            double cur_value = threshold*1.0/a[i]*1.0;
            // cout<<len<<" "<<ns[i]<<" "<<ps[i]<<endl;
            if(cur_value < (double)len){
                return len;
            }
            
        }
        return -1;
    }
};