class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return; // redundant cable

        if (rankv[pu] < rankv[pv]) {
            parent[pu] = pv;
        }
        else if (rankv[pu] > rankv[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rankv[pu]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // Not enough cables
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            if (find(u) != find(v)) {
                unite(u, v);
                components--;
            }
        }

        // To connect 'components' groups, need components - 1 operations
        return components - 1;
    }
};