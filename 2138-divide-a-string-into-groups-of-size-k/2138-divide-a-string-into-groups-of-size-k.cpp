class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int rem=s.size()%k;
        int d=(k-rem+k)%k;
        while((d)--){
            s+=fill;
        }
        vector<string > ans;
        for(int i=0 ; i<s.size() ; i+=k){
            ans.push_back(s.substr(i,k));
        }
        
        return ans;
    }
};