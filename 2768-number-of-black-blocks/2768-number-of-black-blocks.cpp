class Solution {
public:
    map<pair<int, int> , int> mp;
    int N , M;
    int cal(int i , int j){
        if(i < 0 or j < 0 or i >= N or j >= M)return 0;
        if(i + 2 > N or j + 2 > M)return 0;
        
        int cnt = 0;
        for(int k = i ;k < i + 2 ; k++){
            for(int p = j ; p < j + 2 ; p++){
                if(mp[{k, p}]){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        
        for(auto it : coordinates){
            mp[{it[0] , it[1] }]++;
        }
        N = m , M = n;
        vector<long long>ans(5 , 0);
        long long total = (long long )(m - 1)* (long long)(n - 1);
        for(auto it : coordinates){
            int x = it[0];
            int y = it[1];
            
            ans[cal(x , y)]++;
            ans[cal(x-1 , y - 1)]++;
            ans[cal(x - 1 , y)]++;
            ans[cal(x , y - 1)]++;
            
        }
        ans[2] /= 2;
        ans[4] /= 4;
        ans[3] /= 3;
        ans[0] = total - ans[1] - ans[3] - ans[2] - ans[4];
        return ans;
    }
};