class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size();
        int m=words.size();
        int wl=words[0].size();
        unordered_map<string ,int> mp;
        for(auto it : words)mp[it]++;
        vector<int>indi;
        for(int i=0; i<n-m*wl+1 ;i++){
            unordered_map<string , int> temp;
            for(int j=i; j<i+m*wl;j+=wl){
                temp[s.substr(j,wl)]++;
            }
            bool flag=true;
            for(auto it : mp){
                if(temp[it.first]!=mp[it.first]){
                    flag=false;break;
                }
                
            }
            if(flag)indi.push_back(i);
        }
        return indi;
    }
};