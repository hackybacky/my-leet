class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int topc=0,righttopr=m-1,rightbottomc=n-1,bottomr=0;
        vector<int>v;
        vector<vector<bool>> visited(n,vector(m,false));
        while(topc<=righttopr and bottomr<=rightbottomc){
            
            int j=topc;
            while(j<=righttopr and !visited[topc][j]){
                v.push_back(matrix[topc][j]);
                visited[topc][j]=true;
                j++;
            }
            j=topc+1;
            while(j<=rightbottomc and !visited[j][righttopr]){
                v.push_back(matrix[j][righttopr]);
                visited[j][righttopr]=true;
                j++;
            }
            j=righttopr-1;
            while(j>=bottomr and !visited[rightbottomc][j] ){
                v.push_back(matrix[rightbottomc][j]);
                visited[rightbottomc][j]=true;
                cout<<"b"<<matrix[rightbottomc][j]<<endl; 
                j--;
            }
            j=rightbottomc-1;
            while(j>topc and !visited[j][bottomr]){
                v.push_back(matrix[j][bottomr]);
                visited[j][bottomr]=true;
                
                j--;
                
            }
            topc++,righttopr-=1,rightbottomc-=1,bottomr++;
        }
        return v;
    }
};