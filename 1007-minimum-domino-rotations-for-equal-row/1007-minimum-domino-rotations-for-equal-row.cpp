class Solution {
public:
    int n;
    int giveans(map<int,int>&first,map<int,int>&second){
      //n = t.size();
        int ans = n;
        
        for(auto it : first){
            int ele= it.first;
            
            if(it.second+second[ele]>=n){
                //ut<<ele<<" "<<it.second<<" "<<b[ele]<<endl;
                ans=min(ans,second[ele]);
            }
        }
        return ans;
    }
    int minDominoRotations(vector<int>& t, vector<int> &b) {
        map<int,int> first;
        map<int,int> second;
        
        for(int i=0; i<t.size(); i++){
            first[t[i]]++;
            if(t[i]!=b[i])
            second[b[i]]++;
        }
        n=t.size();
        int ans = giveans(first,second);
        
        first.clear();
        second.clear();
        for(int i=0; i<t.size(); i++){
            second[b[i]]++;
            if(t[i]!=b[i])first[t[i]]++;
        }
        ans=min(ans,giveans(second,first));
        if(ans==n)return -1;
        return ans;
    }
};