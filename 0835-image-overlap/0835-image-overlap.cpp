class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n = img1.size();
        vector<int>va , vb;
        for(int i = 0 ; i < n * n ; i++){
            if(img1[i / n][i % n] == 1){
                va.push_back(i / n * 100 + i % n);
            }
        }
        
        for(int i = 0 ; i < n * n ; i++){
            if(img2[i / n][i % n] == 1){
                vb.push_back(i / n * 100 + i % n);
            }
        }
        unordered_map<int , int > cur;
        for(auto it : va){
            for(auto it2 : vb){
                cur[(it - it2)]++;
            }
        }
        int ans = 0;
        for(auto it : cur){
            ans = max(ans , it.second);
        }
        return ans;
    }
};