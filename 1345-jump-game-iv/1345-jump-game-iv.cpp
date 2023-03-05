class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int , vector<int>> mp;
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]].push_back(i);          
        }
        
        priority_queue<vector<int>> pq;
        vector<int> dis(n , INT_MAX);
        dis[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            int d = -v[0] , indi = v[1];
            if(indi == n - 1)
                return d;
            vector<int> stops = mp[arr[indi]];
            if(indi - 1 >= 0)
            stops.push_back(indi - 1);
            if(indi + 1 < n )
            stops.push_back(indi + 1);
            for(auto it : stops){
                if(dis[it] > d + 1)
                    pq.push({-(d + 1) , it }),
                    dis[it] = d + 1;
            }
            mp[arr[indi]].clear();
            
        }
        return -1;
    }
};