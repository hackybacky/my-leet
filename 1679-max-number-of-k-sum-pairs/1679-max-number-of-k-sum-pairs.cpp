class Solution {
public:
    int maxOperations(vector<int>& arr, int k) {
        unordered_map<int,int> freq_hash;
        
        for(auto it : arr)freq_hash[it]++;
        int ans=0;
        for(auto curele : arr){
            int other_ele = k- curele;
            if(freq_hash[ other_ele ]>0 and freq_hash[curele]>0){
                if( other_ele==curele and freq_hash[curele]<2)continue;
                ans++;
                freq_hash[curele]--;
                freq_hash[ other_ele ]--;
            }
        }
        
        return ans;
    
    }
};