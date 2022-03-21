class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> last;
        
        int n = s.size();
        
        for(int i=0; i<n ; i++){
            last[s[i]]=i;
        }
        vector<int> ans;
        int maxi = -1;
        int j = -1;
        for(int i=0; i<n; i++){
            maxi = max(maxi,last[s[i]]);
            if(maxi==i)ans.push_back(i-j),j=i;
        }
        return ans;
    }
};