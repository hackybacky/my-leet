class Solution {
public:
    vector<int> next(vector<int>nums ){
        int n = nums.size();
        vector<int>d(n , 1);
        vector<int>nxt(n , n);
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
            int cur = 0;
            for(int j = 2 ; j * j <= nums[i] ; j++){
                if(nums[i] % j == 0)cur++;
                while(nums[i] % j == 0)nums[i]/= j;
            }
             if(nums[i] > 1)cur++;
            while(st.size() and d[st.top()] < cur ){
                nxt[st.top()] = i;
                st.pop();
            }
            d[i] = cur;
            st.push(i);
            
        }
        return nxt;
    }
    vector<int> rnext(vector<int>nums){
        int n = nums.size();
        vector<int>d(n , 1);
        vector<int>nxt(n , -1);
        stack<int>st;
        for(int i = n - 1 ; i >= 0 ; i--){
            int cur = 0;
            for(int j = 2 ; j * j <= nums[i] ; j++){
                if(nums[i] % j == 0)cur++;
                while(nums[i] % j == 0)nums[i]/= j;
            }
            if(nums[i] > 1)cur++;
            while(st.size() and d[st.top()] <= cur ){
                nxt[st.top()] = i;
                st.pop();
            }
            d[i] = cur;
            st.push(i);
            
        }
        return nxt;
    }
        const int mod = 1e9 + 7;
    long long fastpow(long a,long long b){
    long long res=1;
    while (b>0){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return res%mod;
}
    int maximumScore(vector<int>& nums, int k) {
        
        vector<vector<int>> bnd;
        auto agle = next(nums );
        auto pichle = rnext(nums);
        int n = nums.size();
        for(int i = 0 ; i < n ;i++){
            bnd.push_back({nums[i] , agle[i] , pichle[i] , i});
        }
        sort(bnd.rbegin() , bnd.rend());
        int ans = 1;
        for(int i = 0 ; i < n and k; i++){
            int cntagle = bnd[i][1] - bnd[i][3];
            int cntpichle = bnd[i][3] - bnd[i][2] - 1;
            long long cnt = cntagle ;
            cnt += (long long)cntagle *  (long long)cntpichle;
            cnt = min(cnt , (long long)k);
            ans = (ans * fastpow(bnd[i][0] , cnt))%mod;
            k -= cnt;
            
        }
        return ans;
    }
};