class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>prefix(n + 1,vector<int>(m + 1,0));

        for(int i = 1 ; i <= n ; i ++){
            for(int j = 1 ; j <= m ; j ++){
                prefix[i][j] = mat[i-1][j-1] 
                + prefix[i-1][j] + prefix[i][j-1] 
                - prefix[i-1][j-1];
            }
        }
         // Answer matrix
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                int top = max(0, i - k);
                int bottom = min(n - 1, i + k);

                int left = max(0, j - k);
                int right = min(m - 1, j + k);

                // Convert to prefix matrix coordinates
                top++;
                bottom++;
                left++;
                right++;

                ans[i][j] =
                    prefix[bottom][right]
                    - prefix[top-1][right]
                    - prefix[bottom][left-1]
                    + prefix[top-1][left-1];
            }
        }

        return ans;
    }
};