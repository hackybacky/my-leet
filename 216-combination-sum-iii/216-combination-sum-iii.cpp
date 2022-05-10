class Solution {
public:
    vector<vector<int>>ans;
    
    void backtrack(vector<int>&visited,int cur_su , int k , int n ,int curindi ){
        if(visited.size()==k){
            if(cur_su==n)
            ans.push_back(visited);
            return ;
        }
        if(cur_su>n)return;
        for(int i=curindi; i<=9; i++){
            if(find(visited.begin(),visited.end(),i)==visited.end()){
                visited.push_back(i);
                cur_su+=i;
                backtrack(visited,cur_su,k,n,i+1);
                visited.pop_back();
                cur_su-=i;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>visited;
        backtrack(visited,0,k,n,1);
        return ans;
        
    }
};