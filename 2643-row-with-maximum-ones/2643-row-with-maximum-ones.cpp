class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int idx = 0;
        int maxi = 0;

        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0;

            for (int j = 0; j < mat[0].size(); j++) {
                cnt += mat[i][j];
            }

            if (cnt > maxi) {
                maxi = cnt;
                idx = i;
            }
        }

        return {idx, maxi};
    }
};