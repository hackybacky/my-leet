class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n= pre.size();
        
        vector<int> indeg(numCourses+1,0);
        
        vector<vector<int>> graph(numCourses+1);
        for(int i=0; i< n ; i++){
            int a=pre[i][0];
            int b=pre[i][1];
            indeg[a]++;
            graph[b].push_back(a);
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        
        int cnt=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto it : graph[top]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
            cnt++;
        }
        //cout<<cnt<<endl;
        return cnt==numCourses;
        
    }
};