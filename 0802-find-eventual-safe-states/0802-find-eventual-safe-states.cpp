class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& vis, vector<int>& pathvis,
             vector<int>& check) {

        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : graph[node]) {

            // Cycle found
            if (pathvis[it]) {
                return true;
            }

            // Not visited, perform DFS
            if (!vis[it]) {
                if (dfs(it, graph, vis, pathvis, check)) {
                    return true;
                }
            }
        }

        // No cycle reachable from this node
        check[node] = 1;
        pathvis[node] = 0;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int v = graph.size();

        vector<int> vis(v, 0);
        vector<int> pathvis(v, 0);
        vector<int> check(v, 0);

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathvis, check);
            }
        }

        vector<int> safenode;

        for (int i = 0; i < v; i++) {
            if (check[i] == 1) {
                safenode.push_back(i);
            }
        }

        return safenode;
    }
};