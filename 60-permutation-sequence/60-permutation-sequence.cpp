class Solution {
public:
    string getPermutation(int n, int k) {
        
        
        vector<int>num;
        int fact=1;
        for(int i=1;i<n;i++){
            fact*=i;
            num.push_back(i);
        }
        num.push_back(n);
        
        string ans ="";
        int cur=n-1;
        k--;
        while(1){
            int t = k/fact;
            ans+=(to_string(num[t]));
            num.erase(std::remove(num.begin(), num.end(), num[t]), num.end());
            if(num.size()==0)break;
            k=k%fact;
            fact/=cur;
            cur--;
        }
        return ans;
    }
};