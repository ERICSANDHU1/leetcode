class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int n = grid.size();
      vector<vector<int>>visited(n,vector<int>(n,0));
      if(grid[0][0] == 1)return -1;

      queue<pair<int,int>>q;
      visited[0][0] = 1;
      int path = 1;
      q.push({0,0});

       int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};

     while(!q.empty()){
        int size = q.size();
        while(size--){
          auto node = q.front();
          q.pop();

         int r = node.first;
         int c = node.second;

         if(r == n-1 && c == n-1) return path;
         
          for(int k = 0 ; k < 8 ; k++){
              int nr = r + dr[k];
              int nc = c + dc[k];

             if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0 && !visited[nr][nc]){
              visited[nr][nc] = 1;
              q.push({nr,nc});
              }
            }
         }
         path ++;
      }
      return -1;

    }
};