class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int xo = 0;
        for(auto it :nums)xo ^= it;
        return xo;
    }
};