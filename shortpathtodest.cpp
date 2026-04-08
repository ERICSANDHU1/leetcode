// Given a 2D binary matrix A(0-based index) of dimensions NxM. 
// Find the minimum number of steps required to reach from (0,0) to (X, Y).
// Note: You can only move left, right, up and down, and only through cells that contain 1.

// Input:
// N=3, M=4
// A=[[1,0,0,0], 
//    [1,1,0,1],
//    [0,1,1,1]]
// X=2, Y=3 
// Output:
// 5
// Explanation:
// The shortest path is as follows:
// (0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3)

#include<bits/stdc++.h>
using namespace std;

int shortest(int n , int m , vector<vector<int>>&grid,int X , int Y){
    if(grid[0][0] = 0) return -1;
    vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    q.push({0,0});
    visited[0][0] = 1;
    int path = 0;

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;
            if(r == X && c == Y) return path;

            for(int k = 0  ; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >=0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1 && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        path++;
    }
    return -1;
}
int main(){
    int n , m ; 
    cin >> n >> m ;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> grid[i][j];
        }
    }
    int X , Y;
    cin >> X >> Y;
    int result = shortest(n,m,grid,X,Y);
    cout << result << endl;
}