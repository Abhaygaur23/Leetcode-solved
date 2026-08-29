class Solution {
public:

    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        parent.resize(n * n);
        sz.assign(n * n, 1);

        // Initialize DSU
        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // ------------------------------------------------
        // Step 1: Connect all existing land cells
        // ------------------------------------------------

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 0)
                    continue;

                int node = r * n + c;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int neighbour = nr * n + nc;

                        unite(node, neighbour);
                    }
                }
            }
        }

        // ------------------------------------------------
        // Step 2: Find current maximum island
        // ------------------------------------------------

        int ans = 0;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1) {
                    int node = r * n + c;
                    ans = max(ans, sz[find(node)]);
                }
            }
        }

        // ------------------------------------------------
        // Step 3: Try converting every 0 -> 1
        // ------------------------------------------------

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1)
                    continue;

                int currentSize = 1;

                // Store unique neighbouring components
                set<int> components;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int neighbour = nr * n + nc;

                        components.insert(find(neighbour));
                    }
                }

                // Add sizes of unique islands
                for (int root : components) {
                    currentSize += sz[root];
                }

                ans = max(ans, currentSize);
            }
        }

        return ans;
    }
};