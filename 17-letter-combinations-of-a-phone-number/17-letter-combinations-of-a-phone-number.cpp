class Solution {
public:
    
    auto generate(string digits){
        int k=0;
        vector<string>  v= {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        return v;
    }
    vector<string > ans;
    
    void helper(int i,string digits,vector<string> v,string a){
        if(i>=digits.size()){if(a.size()>0)ans.push_back(a);return ;}
        
        for(auto it : v[digits[i]-'2']){
            cout<<it<<endl;
            helper(i+1 ,digits,v,a+it);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        auto v=generate(digits);
        //cout<<v[2][1]<<endl;
        helper(0,digits,v,"");
        return ans;
    }
};