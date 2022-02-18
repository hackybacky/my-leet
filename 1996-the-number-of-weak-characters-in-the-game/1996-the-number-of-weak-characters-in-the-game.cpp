class Solution {
public:
     static bool cmp(vector<int> &a, vector<int> &b)
     {
          
             return     a[0] < b[0] or (a[0]==b[0] and a[1]>=b[1]);
     }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),cmp);
        int n=properties.size();
        int mx=properties[n-1][1];
        int ans=0;
        for(int i=n-2; i>=0;i--){
            if(properties[i][0]<properties[n-1][0]){
                if(properties[i][1]<mx)ans++;
            }
            mx=max(mx,properties[i][1]);
            
        }
        return ans;
    }
};