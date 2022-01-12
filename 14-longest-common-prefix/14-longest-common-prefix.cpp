class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        
        sort(v.begin(),v.end());
        int n=v.size();
        auto a=v[0];
        auto b=v[n-1];
        string ans="";
        for(int i=0 ; i < min(a.size(),b.size()); i++){
            if(a[i]==b[i])ans+=a[i];
            else break;
        }
        return ans;
    }
};