class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9; // use large number instead of INT_MAX

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

        // Base case: amount = 0 requires 0 coins
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // Fill DP table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                int notTake = dp[i + 1][j]; // skip coin i
                int take = INF;
                if (j >= coins[i] && dp[i][j - coins[i]] != INF) {
                    take = 1 + dp[i][j - coins[i]]; // take coin i
                }
                dp[i][j] = min(notTake, take);
            }
        }

        return dp[0][amount] == INF ? -1 : dp[0][amount];
    }
};
