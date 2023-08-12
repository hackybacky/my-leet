class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        int current = 1;
        vector<int>ans;
        for(int i = 0 ; i < n ;i++){
            ans.push_back(current);
            if(current * 10 <= n)current *=10;
            else if ((current % 10) != 9 and (current + 1) <= n)current++;
            else{
                while((current / 10)%10 == 9 )current /= 10;
                current /= 10 ;
                current++;
            }
        }
        return ans;
    }
};