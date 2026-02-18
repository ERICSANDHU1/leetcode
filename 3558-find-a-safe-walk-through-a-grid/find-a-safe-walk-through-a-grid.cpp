class Solution {
public:
        int n , m ;
        vector<vector<int>>best;
     bool dfs(int i , int j , int health , vector<vector<int>>&grid){
       
        if(i<0 || i>=n || j<0 || j>= m ) return false;

        health -= grid[i][j];
        if(health <= 0) return false;
        if(i == n-1 && j == m -1) return true;

        if(best[i][j] >= health) return false;
        best[i][j] = health;

         return dfs(i+1,j,health,grid) ||
          dfs(i-1,j,health,grid) ||
          dfs(i,j+1,health,grid) ||
          dfs(i,j-1,health,grid);

    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
         n = grid.size();
         m = grid[0].size();
        best.assign(n,vector<int>(m,-1));
        return dfs(0,0,health , grid);
    }
};