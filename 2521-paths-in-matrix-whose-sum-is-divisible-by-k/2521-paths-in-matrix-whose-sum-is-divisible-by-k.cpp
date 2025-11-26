class Solution {
public:
    int m, n, k;
    long long mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    long long solve(int i, int j, int rem, vector<vector<int>>& grid) {
        rem = (rem + grid[i][j]) % k;

        // reached end
        if (i == m - 1 && j == n - 1)
            return rem == 0;

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        long long ans = 0;

        if (j + 1 < n)
            ans = (ans + solve(i, j + 1, rem, grid)) % mod;

        if (i + 1 < m)
            ans = (ans + solve(i + 1, j, rem, grid)) % mod;

        return dp[i][j][rem] = ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int K) {
        m = grid.size();
        n = grid[0].size();
        k = K;
        dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0, 0, 0, grid);
    }
};
