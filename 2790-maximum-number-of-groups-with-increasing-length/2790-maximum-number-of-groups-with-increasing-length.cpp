class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        long long int sum = 0;
        sort(usageLimits.begin() , usageLimits.end());
        int count = 0;
        for(auto it : usageLimits){
            sum += it;
            if(sum >= ((long long)(count + 1)*(long long)(count + 2))/2){
                count++;
            }
        }
        return count;
    }
};