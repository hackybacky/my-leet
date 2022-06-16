class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool f=false,s=false,t=false;
        
        for(auto it : triplets){
            
            if(it[0]==target[0] and it[1]<=target[1] and it[2]<=target[2])f=true;
            if(it[1]==target[1] and it[0]<=target[0] and it[2]<=target[2])s=true;
            
            if(it[2]==target[2] and it[1]<=target[1] and it[0]<=target[0])t=true;
        }
        
        return f and s and t;
    }
};