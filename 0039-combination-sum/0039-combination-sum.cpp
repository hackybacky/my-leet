class Solution {
public:
    vector<vector<int>>ans;
    
    void backtrack(vector<int>&cur,int cur_sum , vector<int>&cand , int target,int k ){
        
        // if(cur.size()==3){
        
        if(cur_sum==target){
            ans.push_back(cur);
            return ;
        }
        
        for(int i=k; i<cand.size(); i++){
            
            if(cur_sum+cand[i]<=target){
                cur_sum+=cand[i];
                cur.push_back(cand[i]);
                backtrack(cur,cur_sum,cand,target,i);
                int j=i+1;
                cur_sum-=cand[i];
                cur.pop_back();
                // while(j<cand.size() and cand[j]==cand[i])i++,j++;
            }
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>c;
        sort(candidates.begin(),candidates.end());
        backtrack(c,0,candidates,target,0);
        return ans;
    }
};