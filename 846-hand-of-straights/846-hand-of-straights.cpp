class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0)return false;
        
        map<int,int>cnt;
        for(auto it : hand)cnt[it]++;
        
        for(auto it : cnt){
            int val = it.first;
            if(it.second>0){
                for(int i=1;i<groupSize;i++){
                    if(cnt[val+i]<it.second){
                        // cout<<it.first<<" "<<val+i<<endl;
                        return false;
                    }
                    cnt[val+i]-=it.second;
                }
            }
        }
        return true;
        
    }
};