class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        map<char,int> mp;
        for(auto it : s)mp[it]++;
        
        string res = "";
        map<char,bool > visited;
        
        for(int i=0; i<s.size(); i++){
            mp[s[i]]--;
            if(visited[s[i]])continue;
            
            while(s[i]<res.back() and mp[res.back()] ){
                visited[res.back()]=false;
                res.pop_back();
            }
            res+=s[i];
            visited[s[i]]=true;
            
        }
        return res;
    }
};