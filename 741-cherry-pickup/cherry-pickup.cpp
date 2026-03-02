class Solution {
public:
    int n;
    int t[51][51][51];

    int solve(vector<vector<int>>& grid,
              int r1, int c1, int r2) {

        int c2 = r1 + c1 - r2;

        // Out of bounds
        if(r1 >= n || c1 >= n ||
           r2 >= n || c2 >= n)
            return -1e9;

        // Thorn
        if(grid[r1][c1] == -1 ||
           grid[r2][c2] == -1)
            return -1e9;

        // Reached end
        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];

        if(t[r1][c1][r2] != -1)
            return t[r1][c1][r2];

        int cherries = grid[r1][c1];
        if(r1 != r2 || c1 != c2)
            cherries += grid[r2][c2];

        int ans = max({
            solve(grid, r1+1, c1, r2+1),  // down, down
            solve(grid, r1, c1+1, r2),    // right, right
            solve(grid, r1+1, c1, r2),    // down, right
            solve(grid, r1, c1+1, r2+1)   // right, down
        });

        return t[r1][c1][r2] = cherries + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        n = grid.size();
        memset(t, -1, sizeof(t));

        int result = solve(grid, 0, 0, 0);

        return max(0, result);
    }
};