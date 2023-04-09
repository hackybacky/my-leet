
 class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>> distance(m,(vector<long long>(n,INT_MAX)));
        distance[0][0]=1;
        priority_queue<pair<long long,pair< int, int>>, vector<pair<long long,pair< int, int>>>, greater<pair<long long,pair< int, int>>>> pq;
        pq.push({1,{0, 0}} );
        while (!pq.empty()) {
            long long d = pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if (i == m-1 && j == n-1) {
                return (int)d;
            }
            for (int k = j+1; k <= min(j+grid[i][j], n-1); k++) {
                if (distance[i][k] > d+1) {
                    distance[i][k] = d+1;
                    pq.push({d+1,{ i, k}});
                    if (i == m-1 && k == n-1) {
                        return (int)d+1;
                    }
                }
            }
            for (int k = i+1; k <= min(i+grid[i][j], m-1); k++) {
                if (distance[k][j] > d+1) {
                    distance[k][j] = d+1;
                    pq.push({d+1, {k, j}});
                    if (k == m-1 && j == n-1) {
                        return (int)d+1;
                    }
                }
            }
        }
        return -1;
    }
};
