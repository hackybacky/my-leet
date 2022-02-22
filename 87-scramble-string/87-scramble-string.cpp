class Solution {
public:
    unordered_map<string, bool> mp;
    
    bool helper(string a, string b)
    {
        if(a.compare(b) == 0) return true;
        
        if(a.length() <= 1) return false;  //1character can't be compared
        
        int n = a.length();
        bool check = false;
        
        string key = a;
        
        key += ' ' + b;
        
        if(mp.find(key) != mp.end()) 
            return mp[key];
        
        for(int i = 1; i < n; i++)
        {
           bool swap = helper(a.substr(0,i), b.substr(n - i,i)) and helper(a.substr(i), b.substr(0, n - i));
           bool unswap = helper(a.substr(0,i), b.substr(0,i)) and helper(a.substr(i,n - i), b.substr(i,n - i));
            
           if(swap || unswap){
               check = true;
               break;
           }
        }
        
        return mp[key] =  check;
    }
    
    bool isScramble(string a, string b) 
    {
        if(a == b) return true;
        
        if(a.length() != b.length()) return false;
        
        if(a.empty() and b.empty()) return true;
        
        return helper(a, b);
    }
};