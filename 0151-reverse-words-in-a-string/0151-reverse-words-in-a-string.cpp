class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin() , s.end());
        
        stringstream ss(s);
        string cur;
        string ans = "";
        while(getline(ss , cur , ' ')){
            // cout << cur << endl;
            if(cur.size() == 0)continue;
            reverse(cur.begin() , cur.end());
            ans += cur + " ";
            
        }
        ans.pop_back();
        return ans;
    }
};