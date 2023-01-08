class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<pair<int , int>, int > mp;
        // sort(points.begin() , points.end());
        int n = points.size();
        int ans = 0 ;
        for(int i = 0 ; i < n ;i++){
            mp.clear();
            for(int j = i + 1 ; j < n ;j++){
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];
                
                int g = __gcd(x , y);
                x /= g;
                y /= g;
                mp[{x , y}]++;
            }
            for(auto it : mp){
                ans = max(ans , it.second);
            }
        }
        return ans+1;
    }
};