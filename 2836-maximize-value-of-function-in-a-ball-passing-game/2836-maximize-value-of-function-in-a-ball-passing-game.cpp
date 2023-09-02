class Solution {
public:
    vector<vector<int>> up;
    vector<vector<long long int>> sum;
    int l;

    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size() ;
        l = 40;
        up.assign(n , vector<int>(l + 1, 0));
        sum.assign(n , vector<long long>(l + 1 , 0));
        vector<int>vis(n , 0);
        
        for(int j = 0 ; j <= l ;j++){
            for(int i = 0; i < n ; i++){
                if(j == 0)up[i][j] = receiver[i] , sum[i][j] = receiver[i];
                else{
                    up[i][j] = up[up[i][j- 1]][j - 1];
                    sum[i][j] = sum[i][j - 1] + sum[up[i][j - 1]][j - 1];
                }
            }
        }
        long long fans = 0;
        for(int i =0 ; i < n ; i++){
            int cur = i;
            long long int csum = i;
            for(long long int j = 0 ; j <= 40 ; j++){
                if( (k &(1ll << j))){
                    csum += sum[cur][j];
                    cur = up[cur][j];
                    // cout << csum << endl;
                }
            }
            fans = max(fans , csum);
        }
        return fans;
        
        
    }
};