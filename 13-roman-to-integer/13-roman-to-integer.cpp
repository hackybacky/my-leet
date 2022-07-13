class Solution {
public:
    int give_value(char c){
        if(c=='I')return 1;
        if(c=='V')return 5;
        if(c=='X')return 10;
        if(c=='L')return 50;
        if(c=='C')return 100;
        if(c=='D')return 500;
        return 1000;
    }
    int romanToInt(string s) {
            
        int n = s.size();
        int ans =0 ;
        for(int i=0 ; i<n ; i++ ){
            if(i-1>=0 and give_value(s[i-1])<give_value(s[i])){
                ans-=give_value(s[i-1])*2;
                
            }
            
            ans+=give_value(s[i]);
            
        }
        return ans;
    }
};