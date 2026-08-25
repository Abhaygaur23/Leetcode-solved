class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // {cost, point}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<bool> visited(n, false);

        // Start from point 0
        pq.push({0, 0});

        int totalCost = 0;
        int count = 0;

        while (!pq.empty() && count < n) {
            auto [cost, u] = pq.top();
            pq.pop();

            // Already included in MST
            if (visited[u])
                continue;

            // Add point to MST
            visited[u] = true;
            totalCost += cost;
            count++;

            // Try connecting u to every unvisited point
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    pq.push({dist, v});
                }
            }
        }

        return totalCost;
    }
};