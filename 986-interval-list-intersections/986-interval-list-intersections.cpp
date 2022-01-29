class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<firstList.size() and j<secondList.size()){
            
            int first_start=firstList[i][0];
            int first_end=firstList[i][1];
            int second_start=secondList[j][0];
            int second_end=secondList[j][1];
            
            if(first_start>second_end)j++;
            else if(second_start>first_end)i++;
            else if(second_start>second_end)j++;
            else if(first_start>first_end)i++;
            else{
                int start=max(first_start,second_start);
                int end;
                if(first_end<second_end){
                    end=first_end;
                    secondList[j][0]=first_end+1;
                    i++;
                }else{
                    end=second_end;
                    firstList[i][0]=second_end+1;
                    j++;
                }
                ans.push_back({start,end});
            }
  
        }
        return ans;
    }
};