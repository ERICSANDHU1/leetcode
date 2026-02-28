class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Min-heap: {cost, x, y}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!pq.empty()) {

            vector<int> top = pq.top();
            pq.pop();

            int cost = top[0];
            int x = top[1];
            int y = top[2];

            // If reached destination
            if (x == m - 1 && y == n - 1)
                return cost;

            // If already found better path, skip
            if (cost > dist[x][y])
                continue;

            for (int d = 0; d < 4; d++) {

                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int edgeCost = (grid[x][y] == d + 1) ? 0 : 1;
                int newCost = cost + edgeCost;

                if (newCost < dist[nx][ny]) {

                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};