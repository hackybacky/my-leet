class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n  = heights.size();
        int l = 0 , r=n-1;
        int ans=0;
        while(l<=r){
            int mid = (l+r)/2;
            
            priority_queue<int>pq;
            for(int i=0;i<mid; i++){
                if(heights[i+1]>heights[i]){
                    pq.push(heights[i+1]-heights[i]);
                }
            }
            int lad = ladders;
            int breq=0;
            while(!pq.empty()){
                auto t= pq.top();
                pq.pop();
                if(lad>0)lad--;
                else breq +=t;
            }
            if(breq<=bricks){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};