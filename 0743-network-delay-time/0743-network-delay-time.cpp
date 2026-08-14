class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // adjacency list
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        // {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // outdated entry
            if (d > dist[node])
                continue;

            for (auto &it : adj[node]) {

                int nextNode = it.first;
                int weight = it.second;

                if (d + weight < dist[nextNode]) {
                    dist[nextNode] = d + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int ans = 0;

        // Find the farthest node
        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};