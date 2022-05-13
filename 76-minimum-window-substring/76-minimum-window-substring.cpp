class Solution {
public:
    string minWindow(string s, string t) {
        int begin=0,end=0;
        
        int n  = s.size();
        map<char,int> count;
        for(auto it:t)count[it]++;
        int counter=t.size();
        int d=INT_MAX;
        int head=0;
        while(end<n){
            if( count[s[end++]]-->0 )counter--;
            
            
            while(counter==0){
                if( end-begin<d )d=end-(head=begin);
                if(count[s[begin++]]++==0)counter++;
                
            }
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};