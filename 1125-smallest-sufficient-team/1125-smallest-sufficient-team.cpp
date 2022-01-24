class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        unordered_map<string,int> skill_mp;
        
        for(int i=0 ; i<req_skills.size(); i++){
            skill_mp[req_skills[i]]=i;
        }
        int n=req_skills.size();
        int person_size=people.size();
       map<int,vector<int>> dp;
        //dp.reserve(1<<n);
        dp[0]={};
        for(int i=0 ; i<person_size ; i++){
            
            int cur_skills=0;
            for(auto it : people[i]){
                cur_skills |= (1<<(skill_mp[it]));
            }
            
            for(auto it :dp){
                
                int comb=(it.first | cur_skills);
                
                if(dp.find(comb)==dp.end()  || dp[comb].size()>(it.second).size()+1){
                    dp[comb]=it.second;
                    dp[comb].push_back(i);
                }
            }
            
            
        }
        
       
        
    return    (dp[(1<<n)-1]);
        
    
        
    }
};