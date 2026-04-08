class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({0,0,0});
        dist[0][0] = 0;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!pq.empty()){

            vector<int> top = pq.top();
            pq.pop();

            int effort = top[0];
            int r = top[1];
            int c = top[2];

            if(r == m-1 && c == n-1)
                return effort;

            for(int d=0; d<4; d++){

                int nr = r + dx[d];
                int nc = c + dy[d];

                if(nr>=0 && nc>=0 && nr<m && nc<n){

                    int diff = abs(heights[r][c] - heights[nr][nc]);

                    int newEffort = max(effort, diff);

                    if(newEffort < dist[nr][nc]){

                        dist[nr][nc] = newEffort;

                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};