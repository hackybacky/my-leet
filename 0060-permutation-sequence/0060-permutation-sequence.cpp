class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>perm;
        int cur = 1;
        map<int , int>mp;
    
        for(int i = 1; i < n ;i++){
            cur = cur * i;
            perm.push_back(i);
            mp[i] = cur;
        }
        perm.push_back(n);
        // n -= 1;
        int d = n - 1;
        string ans = "";
        k--;
        while(1 ){
            int div = k / cur;
            ans += to_string(perm[div]);
            // perm.erase(pe'rm.begin() + div);
            cout << div << endl;
            perm.erase(perm.begin() + div );
            if(perm.size() == 0)break;
            k = k % cur;
            cur /= d;
            d--;
        
            
        }
        return ans;
    }
};