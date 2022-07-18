class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> ans;
        
        unordered_map<int,int> row,col,diag,anti_diag;
        set<pair<int,int>> s;
        
        for(auto &lamp:lamps)
        {
            int x=lamp[0];
            int y=lamp[1];
             if (s.find({x,y}) ==s.end())
            row[x]++,
            col[y]++,
            diag[x+y]++,
            anti_diag[x-y]++,
            s.insert({lamp[0],lamp[1]});

        }
        
        for(auto &q : queries)
        {
            int qx=q[0];
            int qy=q[1];
            
            if(row[qx]>0 or col[qy]>0 or diag[qx+qy]>0 or anti_diag[qx-qy]>0)
            {
                ans.push_back(1);
                
                
                for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                        int xele=qx+i;
                        int yele=qy+j;
                        
                        if(xele>=0 and xele<n and yele>=0 and yele<n and s.find({xele,yele})!=s.end())
                        {
                            s.erase({xele,yele});
                            row[xele]--;
                            col[yele]--;
                            diag[xele+yele]--;
                            anti_diag[xele-yele]--;
                        }
                    }
                }
                
            }
            else
            {
                ans.push_back(0);
            }
        }
        
        return ans;

    }
};