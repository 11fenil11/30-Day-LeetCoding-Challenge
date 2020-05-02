class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        int dp[m+1][n+1];
        dp[0][0] = matrix[0][0] == '1' ? 1 : 0;
        int res = dp[0][0];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    res = max(dp[i][j], res);
                }
            }
        }
        return res * res;
    }
};
