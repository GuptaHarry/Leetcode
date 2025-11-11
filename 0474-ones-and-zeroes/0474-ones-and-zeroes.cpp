class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();

        // dp[i][j] = max number of strings using i zeros and j ones
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string s : strs) {
            int zeros = 0, ones = 0;

            // count zeros and ones in this string
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }

            // traverse backwards (0/1 knapsack rule)
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    }
};
