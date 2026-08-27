class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

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

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // email -> account index
        map<string, int> mp;

        // Step 1: Connect accounts having common emails
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (mp.find(email) == mp.end()) {
                    mp[email] = i;
                }
                else {
                    unite(i, mp[email]);
                }
            }
        }

        // parent -> all emails belonging to that component
        map<int, vector<string>> merged;

        for (auto &it : mp) {

            string email = it.first;
            int account = it.second;

            int root = find(account);

            merged[root].push_back(email);
        }

        // Build answer
        vector<vector<string>> ans;

        for (auto &it : merged) {

            int root = it.first;
            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> temp;

            // Name of the account
            temp.push_back(accounts[root][0]);

            // Add emails
            for (string &email : emails)
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};