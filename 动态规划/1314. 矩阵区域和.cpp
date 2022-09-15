#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1;  i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mat[i-1][j-1];
            }
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0;  i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 计算左上角坐标 (row1, col1) 和右下角坐标 (row2, col2)
                int row1 = max(i - K, 0), col1 = max(j - K, 0);
                int row2 = min(i + K, m - 1), col2 = min(j + K, n - 1);
                ans[i][j] = prefix[row2+1][col2+1] - prefix[row2+1][col1] - prefix[row1][col2+1] + prefix[row1][col1];
            }
        }
        return ans;
    }
};

