class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int , int >> vp;
        int n = plantTime.size();
        for(int i = 0 ; i < n ; i++){
            vp.push_back({growTime[i] , plantTime[i]});
        }
        
        sort(vp.rbegin() , vp.rend());
        
        int plant_time = 0 , grow_time = 0;
        
        for(int i = 0 ; i < n ; i++){
            plant_time += vp[i].second;
            int gt = vp[i].first;
            if(plant_time + gt > grow_time ){
                grow_time = plant_time + gt;
            }
            
        }
        return max(grow_time , plant_time);
    }
};