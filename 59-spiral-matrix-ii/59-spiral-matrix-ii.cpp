class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v( n, vector<int> (n));
         int i=0; int k=1;
        while(k<=n*n){
            int j=i;
            while(j<n-i){
                v[i][j++]=k++;
            }
            j=i+1;
            
            while(j<n-i){
                v[j++][n-i-1]=k++;
            }
            j=n-i-2;
            while(j>i){
                v[n-i-1][j--]=k++;
            }
            j=n-i-1;
            while(j>i){
                v[j--][i]=k++;
            }
            i++;
               
            }
        return v;
        }
    
};