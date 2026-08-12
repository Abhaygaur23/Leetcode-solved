class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathvis) {

        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node]) {

            // Cycle detected
            if (pathvis[it])
                return true;

            // Not visited
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathvis))
                    return true;
            }
        }

        pathvis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // prerequisite -> course
        for (auto edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {
                if (dfs(i, adj, vis, pathvis))
                    return false;
            }
        }

        return true;
    }
};