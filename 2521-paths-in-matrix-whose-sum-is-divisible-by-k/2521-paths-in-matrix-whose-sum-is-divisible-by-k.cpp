class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        long long mod = 1e9 + 7;

        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(k, 0)));

        // BASE CASE
        dp[0][0][grid[0][0] % k] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int r = 0; r < k; r++){

                    if(dp[i][j][r] == 0) continue;

                    // move down
                    if(i + 1 < m){
                        int new_r = (r + grid[i + 1][j]) % k;
                        dp[i + 1][j][new_r] = (dp[i + 1][j][new_r] + dp[i][j][r]) % mod;
                    }

                    // move right
                    if(j + 1 < n){
                        int new_r = (r + grid[i][j + 1]) % k;
                        dp[i][j + 1][new_r] = (dp[i][j + 1][new_r] + dp[i][j][r]) % mod;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
