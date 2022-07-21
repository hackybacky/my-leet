class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int mx = -1;
        int cnt=0;
        for(int i=0;i<arr.size(); i++){
            mx=max(mx,arr[i]);
            if(i==mx)cnt++;
        }
        return cnt;
    }
};