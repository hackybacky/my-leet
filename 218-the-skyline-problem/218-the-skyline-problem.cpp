class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // [x, building index]
        vector<pair<int, int>> edges;
        for (int i = 0; i < buildings.size(); i++) {
            edges.push_back({buildings[i][0], i});
            edges.push_back({buildings[i][1], i});
        }
        sort(edges.begin(), edges.end());
        // [y, x end]
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
        vector<vector<int>> res;
        int y = 0;
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i].first;
            // Push all height of buildings starting from x
            while (i < edges.size() && edges[i].first == x) {
                int ind = edges[i].second;
                if (buildings[ind][0] == x) {
                    q.push({buildings[ind][2], buildings[ind][1]});
                }
                i += 1;
            }
            i -= 1;
            // Pop all height of buildings lag behind x
            while (!q.empty() && q.top().second <= x) {
                q.pop();
            }
            // Get current height
            int h = q.empty() ? 0 : q.top().first;
            if (y != h) {
                res.push_back({x, h});
                y = h;
            }
        }
        return res;
    }
};