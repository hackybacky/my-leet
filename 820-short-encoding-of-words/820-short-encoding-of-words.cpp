class Solution {
public:
    static bool cmp(string & a , string &b){
        return a.size()>b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        
        sort(words.begin(),words.end(),cmp);
        map<string , int >mp;
        int ans=0;
        string res="";
        for(auto it : words){
            auto it2 = res.find(it+"#");
            if(it2==-1){
                res+=it+"#";
            }
            
        }
        return res.size();
    }
};