class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {

        int n = adj.size();

        vector<int> color(n, -1);

        for(int start = 0; start < n; start++) {

            // New disconnected component
            if(color[start] != -1)
                continue;

            queue<int> q;

            color[start] = 0;
            q.push(start);

            while(!q.empty()) {

                int node = q.front();
                q.pop();

                for(auto it : adj[node]) {

                    // Not colored yet
                    if(color[it] == -1) {

                        color[it] = !color[node];
                        q.push(it);

                    }
                    // Same color as current node
                    else if(color[it] == color[node]) {

                        return false;
                    }
                }
            }
        }

        return true;
    }
};