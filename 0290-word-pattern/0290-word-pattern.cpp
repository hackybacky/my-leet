class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        stringstream st(s);
        map<string , int > mp;
        map<char , int> mp2;
        int i = 0;
        string str;
        while(getline(st , str , ' ')){
            
            if(mp[str] == 0 and mp2[pattern[i]] == 0){
                mp[str] = i + 1;
                mp2[pattern[i]] = i + 1;
            }
            else if(mp[str] != mp2[pattern[i]])return false;
            i++;
        }
        return i == pattern.size();
    
    }
};