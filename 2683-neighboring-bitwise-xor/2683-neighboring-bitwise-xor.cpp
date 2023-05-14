class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = 0;
        for(auto it : derived){
            sum += it;
        }
        return sum % 2 == 0 ;
    }
};