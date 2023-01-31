class Solution {
public:
    vector<vector<int>> dp;
    int recur(int last , int current , vector<int>&scores , vector<int>&ages){
        if(current == scores.size())
            return 0;
        if(dp[last][current] != -1){
            return dp[last][current];
        }
        int lastage = ages[last];
        int lastscore = scores[last];
        int currentage = ages[current];
        int currentscore = scores[current];
        int ans ;
        if(lastage < currentage and lastscore > currentscore){
            ans = recur(last , current + 1 , scores , ages);
        }
        else {
            ans = currentscore + recur(current , current + 1 , scores , ages  );
            ans = max(ans , recur(last , current + 1 , scores , ages));
        }
        return dp[last][current] = ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        vector<pair<int, int>> vp;
        for(int i = 0 ; i < n ;i++){
            vp.push_back({ages[i] , scores[i]});
        }
        sort(vp.begin() , vp.end());
        for(int i = 0 ; i < n ; i++){
            scores[i] = vp[i].second;
            ages[i] = vp[i].first;
            
        }
        dp.assign(n , vector<int>(n , -1));
        
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , recur(i , i + 1 , scores , ages) + scores[i]);
        }
        return ans;
    }
};