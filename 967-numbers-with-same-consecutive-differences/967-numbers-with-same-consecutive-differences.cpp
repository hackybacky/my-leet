class Solution {
public:
    vector<int>ans;
    int k;
    void helper( int i , int prev ,int num , int n ){
        if(i==n){
            ans.push_back(num);
            return ;
        }
        
        if(prev+k<10)helper(i+1,prev+k , num*10+prev+k,n);
        
        if(prev-k>=0 and prev-k!=prev+k)helper(i+1,prev-k, num*10+prev-k,n);
    }
    vector<int> numsSameConsecDiff(int n, int K) {
        k=K;
        for(int i=1;i<=9;i++){
            helper(1,i,i,n);
        }
        return ans;
    }
};