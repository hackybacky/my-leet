class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        int n = nums1.size() , m = nums2.size();
        
        int i = 0 , j = 0 ;
        // k = min(k , m * n);
        priority_queue<vector<int>> pq;
        pq.push({-nums1[0] - nums2[0]  , 0 , 0});
        while(k and !pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int x = tp[1] , y = tp[2];
            ans.push_back({nums1[x] , nums2[y]});
            if(y + 1 < m)pq.push({-(nums1[x] + nums2[y + 1]) , x , y + 1});
            if (y == 0 and x + 1 < n){
                pq.push({-(nums1[x + 1] + nums2[0]) , x + 1 , 0});
            }
            k--;
        }
        return ans;
    }
};