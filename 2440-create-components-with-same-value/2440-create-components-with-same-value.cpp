class Solution {
public:
    vector<vector<int>>graph;
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        int n = nums.size();
        graph.assign(n + 1, {});
        vector<int>indeg(n , 0);
        for(auto it : edges){
            int a = it[0] , b = it[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            indeg[a]++;
            indeg[b]++;
        }
        
        int ans = 0;
        auto v = indeg;
        /// topological sorting function
        int part = 0;
        auto v2 = nums;
        auto topo = [&](int target ){
            indeg = v;
            queue< int > q;
            nums = v2;
            for(int i = 0 ; i < n ; i++){
                if(indeg[i] == 1){
                    q.push(i);
                    // indeg[i] = 0;
                    // cout << i <<endl;
                }
            }
            while(!q.empty()){
                auto f = q.front();
                q.pop();
                auto node = f;
                int value = nums[node];
                // cout << node << " " << value << " "<<target <<endl;
                bool flag = false;
                if(value == target){
                    // cout << "hello" <<endl;
                    part++;
                }
                else if(value > target){
                    // cout << "j";
                    return false;
                }
                else{
                    for(auto it : graph[node]){
                        if(indeg[it]  > 0){
                         // ?   cout << "d" <<node << value <<" "<< it <<endl;
                            nums[it] += value;
                        }
                    }
                }
                for(auto it : graph[node]){
                    indeg[it]--;
                    if(indeg[it] == 1){
                        flag = true;
                        // indeg[it] = 0;
                        q.push(it);
                    }
                
                    
                }
               
                if(q.empty() ){
                    // part++;
                    // cout << value<< " v "<<node << endl;
                    return value == target;
                }
                indeg[node] = 0;
                // 
            }
            
            return true;
        };
        ///////
        // topo(6);
        // cout  << part << endl;
        // cout << topo(6) << " "<< part <<endl;
        for(int i = 1 ; i * i<= sum ;i++){
            if(sum % i == 0){
                int cur = sum / i;
                part = 0;
                
                if(topo(cur) and part == i){
                    ans = max(ans , i - 1);
                }
                // cout << part <<endl;
                cur = i;
                part = 0;
                if(topo(cur) and part == sum / i){
                    ans = max(ans , sum / i - 1);
                }
            }
        }
        return ans;
    }
};