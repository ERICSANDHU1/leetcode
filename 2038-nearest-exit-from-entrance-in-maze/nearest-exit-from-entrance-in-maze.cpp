class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});        // ✅ fix: [0],[1] not .first,.second
        visited[entrance[0]][entrance[1]] = 1;     // ✅ fix: same here

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int steps = 0;

        while(!q.empty()){
            int size = q.size();
        steps++;                               // ✅ increment per level

            while(size--){
                auto node = q.front();
                q.pop();

                int r = node.first;
                int c = node.second;

                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr < 0 || nc < 0 || nr >= n || nc >= m || maze[nr][nc] == '+' || visited[nr][nc]) continue;  // out of bounds
                    // if(maze[nr][nc] == '+') continue;                      // wall
                    // if(visited[nr][nc]) continue;                          // visited

                    // ✅ EXIT CONDITION: border cell that is not entrance
                    if(nr == 0 || nr == n-1 || nc == 0 || nc == m-1)
                        return steps;

                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};