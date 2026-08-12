class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<int>& pathvis,
             vector<vector<int>>& adj, stack<int>& st) {

        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node]) {

            // Cycle detected
            if (pathvis[it]) {
                return true;
            }

            // Not visited
            if (!vis[it]) {
                if (dfs(it, vis, pathvis, adj, st)) {
                    return true;
                }
            }
        }

        pathvis[node] = 0;
        st.push(node);

        return false;
    }

    vector<int> findOrder(int v, vector<vector<int>>& edges) {

        vector<vector<int>> adj(v);

        // prerequisite -> course
        for (int i = 0; i < edges.size(); i++) {

            int course = edges[i][0];
            int prerequisite = edges[i][1];

            adj[prerequisite].push_back(course);
        }

        vector<int> vis(v, 0);
        vector<int> pathvis(v, 0);
        stack<int> st;

        for (int i = 0; i < v; i++) {

            if (!vis[i]) {

                if (dfs(i, vis, pathvis, adj, st)) {
                    return {};
                }
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};