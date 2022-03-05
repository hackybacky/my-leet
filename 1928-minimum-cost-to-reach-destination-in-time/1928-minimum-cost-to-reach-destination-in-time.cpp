class Solution {
    typedef array<int, 3> Node; // node, time, cost
public:
    int minCost(int maxTime, vector<vector<int>>& E, vector<int>& F) {
        int N = F.size();
        vector<unordered_map<int, int>> G(N);
        vector<int> minTime(N, maxTime + 1);
        for (auto &e : E) {
            int u = e[0], v = e[1], t = e[2];
            if (G[u].count(v)) { // For duplicated edges, we just need to keep track of the edge with smallest time.
                G[u][v] = G[v][u] = min(G[u][v], t);
            } else {
                G[u][v] = G[v][u] = t;
            }
        }
        auto cmp = [](auto &a, auto &b) { return a[2] > b[2]; }; // min-heap: Heap top is the 
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        pq.push({0, 0, F[0]});
        minTime[0] = 0;
        while (pq.size()) {
            auto [u, time, c] = pq.top();
            pq.pop();
            if (u == N - 1) return c;
            for (auto &[v, t] : G[u]) {
                int nt = time + t, nc = c + F[v];
                if (nt < minTime[v]) {
                    minTime[v] = nt;
                    pq.push({v, nt, nc});
                }
            }
        }
        return -1;
    }
};