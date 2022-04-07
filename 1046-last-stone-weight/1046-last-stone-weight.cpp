class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> s;
        
        for(auto it :stones)s.insert(it);
        
        while(!s.empty()){
            auto it = *(prev(s.end()));
            s.erase(prev(s.end()));
            
            if(s.empty())return it;
            
            auto second = *(prev(s.end()));
            s.erase(prev(s.end()));
            
            if(it-second>0){
                s.insert(it-second);
            }
            
            
        }
        return 0;
    }
};