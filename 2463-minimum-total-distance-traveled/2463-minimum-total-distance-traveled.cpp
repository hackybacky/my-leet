class Solution {
public:
    long long int dp[101][10001];
    long long recur(int cur , int prev , vector<int> &factory , vector<int>&robot){
        
        if(cur == robot.size()){
            return 0;
        }
        if(prev == factory.size()){
            return 1e12;
        }
        if(dp[cur][prev] != -1){
            return dp[cur][prev];
        }
        long long ans = LLONG_MAX;
        
       
        long long curdis = abs(factory[prev] - robot[cur]);
        ans = min(ans , curdis + recur(cur + 1 , prev + 1 , factory , robot ));
        ans = min(ans , recur(cur  , prev + 1 , factory , robot));
        
        
        return dp[cur][prev] = ans;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        memset(dp , -1 ,sizeof(dp));
        
        sort(robot.begin() , robot.end());
        sort(factory.begin() , factory.end());
        vector<int>v;
        for(auto it : factory){
            int t = it[1];
            for(int i = 0 ; i < t ; i++){
                v.push_back(it[0]);
            }
        }
        return recur(0 , 0 , v , robot);
    }
};