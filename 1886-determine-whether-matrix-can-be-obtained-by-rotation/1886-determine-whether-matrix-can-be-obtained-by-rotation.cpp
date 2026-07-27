class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    bool same(vector<vector<int>>& a, vector<vector<int>>& b) {
        return a == b;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        for (int i = 0; i < 4; i++) {
            if (same(mat, target))
                return true;

            rotate(mat);
        }

        return false;
    }
};