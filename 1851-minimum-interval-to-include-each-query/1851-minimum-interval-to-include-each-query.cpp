class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        set<int>s(queries.begin(),queries.end());
        
        
        priority_queue<pair<int,int>>pq;
        
        for(auto it :intervals){
            int dis = it[1]-it[0];
            pq.push({-dis,it[1]});
        }
        map<int,int>ans;
        while(!pq.empty() and !s.empty()){
            auto t= pq.top();
            pq.pop();
            int dis = t.first;
            int r= t.second;
            int l = r+dis;
            dis=abs(dis);
            auto low = s.lower_bound(l);
            auto up = s.upper_bound(r);
            for(auto it = low ;it!=up and it!=s.end() ; it++){
                if(ans.find(*it)==ans.end())ans[*it]=dis;
                else{
                    ans[*it]=min(ans[*it],dis);
                }
            }
            if((up)!=s.end() and low!=s.end())
                s.erase(low,(up));
        }
        vector<int>cur;
        for(auto it :queries){
            if(ans.find(it)!=ans.end())
            cur.push_back(ans[it]+1);
            else cur.push_back(-1);
        }
        return cur;
    }
};