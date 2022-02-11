class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> ms;
        
        unordered_map<char,int> cur;
        if(s2.size()<s1.size())return false;
        for(auto it : s1)ms[it]++;
        
        for(int i=0; i<s1.size(); i++){
            cur[s2[i]]++;
        }
        
        if(cur == ms){
            return true;
        }
        int j=0;
        for(int i=s1.size(); i<s2.size(); i++,j++){
            cur[s2[j]]--;
            cur[s2[i]]++;
            bool flag =false;
            for(auto it : cur){
              //  cout<<it.first<<" "<<it.second<<endl;
                if( it.second != ms[it.first]){
                    flag=true;
                    break;
                }
            }
            if(!flag)return true;
        }
        return false ;
    }
};