class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>p(26, 0);
        for(auto it : sentence){
            int c = it - 'a';
            p[c] = 1;
        }
        int ans = 0;
        for(int i =0 ; i < 26 ; i++)
            ans += p[i];
        return ans == 26;
    }
};