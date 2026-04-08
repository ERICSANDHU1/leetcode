class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        dp[0][0] = triangle[0][0];
        
        for (int r = 1; r < n; r++) {
            
            // Left edge
            dp[r][0] = dp[r-1][0] + triangle[r][0];
            
            // Middle elements
            for (int c = 1; c < r; c++) {
                dp[r][c] = triangle[r][c] + 
                           min(dp[r-1][c-1], dp[r-1][c]);
            }
            
            // Right edge
            dp[r][r] = dp[r-1][r-1] + triangle[r][r];
        }
        
        int ans = INT_MAX;
        for (int c = 0; c < n; c++) {
            ans = min(ans, dp[n-1][c]);
        }
        
        return ans;
    }
};