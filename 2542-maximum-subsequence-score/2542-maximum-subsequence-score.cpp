class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int>pq;
        
        vector<pair<int , int>> vp;
        int n = nums1.size();
        for(int i = 0 ; i < n ; i++){
            vp.push_back({nums2[i] , nums1[i]});
        }
        
        sort(vp.begin() ,vp.end());
        long long sum = 0;
        for(int i = n - k + 1 ; i < n ; i++){
            pq.push(-vp[i].second);
            sum += vp[i].second;
        }
        long long ans = 0;
        for(int i = n - k ; i >=0 ; i--){
            
            long long nsum = sum + vp[i].second;
            long long mini = vp[i].first;
            ans = max(ans , nsum * mini);
            if(pq.empty())continue;
            int t = -pq.top();
            if(t < vp[i].second){
                pq.pop();
                pq.push(-vp[i].second);
                sum -= t ;
                sum += vp[i].second;
            }
        }
        return ans;
    }
};