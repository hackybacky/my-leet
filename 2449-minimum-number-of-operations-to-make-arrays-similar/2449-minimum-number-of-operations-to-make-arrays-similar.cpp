class Solution {
public:
    long long give_ans(priority_queue<int>&pqe , priority_queue<int>&rpqe){
        long long ans = 0;
        while(!pqe.empty() and !rpqe.empty()){
            auto c = pqe.top();
            pqe.pop();
            auto rc = rpqe.top();
            rpqe.pop();
            if(rc > c){
                ans += (rc - c)/2;
            }
        }
        return ans;
    }
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        
        priority_queue<int > pqo , pqe , rpqo , rpqe;
        
        for(auto it : nums){
            if(it % 2 == 0){
                pqe.push(it);
            }
            else pqo.push(it);
        }
        for(auto it : target){
            if(it % 2 == 0){
                rpqe.push(it);
            }
            else rpqo.push(it);
        }
        
        ans = give_ans(pqe , rpqe);
        ans += give_ans(pqo , rpqo);
        
        return ans;
    }
};