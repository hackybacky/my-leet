class Solution {
public:
    int maxOperations(vector<int>& arr, int k) {
        unordered_map<int,int> freq_hash;
        
        for(auto it : arr)freq_hash[it]++;
        int ans=0;
        for(auto curele : arr){
            if(freq_hash[k-curele]>0 and freq_hash[curele]>0){
                if(k-curele==curele and freq_hash[curele]<2)continue;
                ans++;
                freq_hash[curele]--;
                freq_hash[k-curele]--;
            }
        }
        
        return ans;
    
    }
};