#include<bits/stdc++.h>
using namespace std;
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        // Initialize first row
        for (int j = 0; j < m; j++)
            dp[0][j] = grid[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {          // previous column
                for (int k = 0; k < m; k++) {      // current column
                    dp[i][k] = min(dp[i][k],
                        dp[i-1][j] 
                        + moveCost[grid[i-1][j]][k] 
                        + grid[i][k]);
                }
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }