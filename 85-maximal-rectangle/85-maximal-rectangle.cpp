class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        int n=a.size();
        int m= a[0].size();
        
        vector<vector<int>> height(n+1,vector<int>(m+1,0));
        
        int ans=0;
        
        for(int i=0 ; i<n ;i++){
            for(int j=0; j<m  ;j++){
                int right=0;
                for(int k=j; k<m; k++){
                    if(a[i][k]=='1'){
                        right++;
                        height[i][k]=1;
                        height[i][k]+=(i-1>=0?height[i-1][k]:0);
                    }
                    else break;
                    int d= k-1>=j?height[i][k-1]:1e9;              
                    height[i][k]= min(height[i][k],d);
                  
                    ans=max(ans,height[i][k]*right);
                   
                   // if(i==2 and j==0)cout<<curh<<endl;
                }
            }
        }
        return ans;
    }
};