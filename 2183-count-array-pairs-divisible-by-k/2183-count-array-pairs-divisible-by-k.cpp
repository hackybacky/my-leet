class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        map<long long ,long long > check;
        vector<int>a;
        for(int i=1; i*i<=k; i++){
            if(k%i==0){
                a.push_back(i);
                if(k/i!=i)
                a.push_back(k/i);
            }
        }
        long long ans=0;
        int kk=0;
        for(auto it : nums){
           
            ans+=check[k/(__gcd(k,it))];
            for(auto it2:a){
                if(it%it2==0)check[it2]++;
            }
           
            kk++;
        }
        
        return ans;
    }
};