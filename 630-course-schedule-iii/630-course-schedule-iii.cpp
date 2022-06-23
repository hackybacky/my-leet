class Solution {
public:
    // int dp[10001][10001];
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        
        int time=0;
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int>pq;
        for(auto it : courses){
            int dur = it[0],end = it[1];
            if(dur+time<=end){
                time += dur;
                pq.push(dur);
            }
            else{
                if(!pq.empty() and pq.top()>dur){
                    time-=pq.top();
                    pq.pop();
                    time+=dur;
                    pq.push(dur);
                }
            }
        }
        return pq.size();
    }
};