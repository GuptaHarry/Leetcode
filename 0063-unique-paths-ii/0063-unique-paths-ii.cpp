class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();

        if (a[0][0] == 1 || a[m-1][n-1] == 1) return 0;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        dp[m-1][n-1] = 1;

        // last row
        for (int j = n-2; j >= 0; j--) {
            if (a[m-1][j] == 0) dp[m-1][j] = dp[m-1][j+1];
            else dp[m-1][j] = 0;
        }

        // last column
        for (int i = m-2; i >= 0; i--) {
            if (a[i][n-1] == 0) dp[i][n-1] = dp[i+1][n-1];
            else dp[i][n-1] = 0;
        }

        // rest of the grid
        for (int i = m-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                if (a[i][j] == 0)
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                else
                    dp[i][j] = 0;
            }
        }

        return (int)dp[0][0]; // final answer fits into int
    }
};
