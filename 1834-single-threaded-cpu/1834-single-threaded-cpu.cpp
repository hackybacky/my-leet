class Solution {
public:
    // struct cmp {
    // bool operator()(vector<int> const& p1, vector<int> const& p2)
    // {
    //     // return "true" if "p1" is ordered
    //     // before "p2", for example:
    //     return p1[0] > p2 [0]
    //     // return p1.height < p2.height;
    // }
// };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int,int>>> pq;
        int n = tasks.size();
        for(int i = 0 ;i < n ; i++){
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin() , tasks.end());
        long long  arr = tasks[0][0];
        vector<int>ans;
        int ind = 0;
        while(ind < n or !pq.empty()){
            if(pq.empty()){
                arr =  max(arr ,(long long )tasks[ind][0]);
            }
            while(ind < n and (arr >= tasks[ind][0] )){
                pq.push({tasks[ind][1] , tasks[ind][2]});
                ind++;
            }
            pair<int , int> t = pq.top();
            pq.pop();
            ans.push_back(t.second);
            // long long d = t.first + tasks[ind][0];
            arr += t.first;
        }
        return ans;
    }
};