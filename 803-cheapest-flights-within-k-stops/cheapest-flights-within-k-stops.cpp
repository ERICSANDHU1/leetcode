class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back(make_pair(v, w));
        }

        // Min-heap: {cost, node, stops}
        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        // Use long long for distance to avoid overflow
        vector<vector<long long>> dist(n, vector<long long>(k + 2, LLONG_MAX));

        pq.push(vector<long long>{0, src, 0});
        dist[src][0] = 0;

        while (!pq.empty()) {

            vector<long long> top = pq.top();
            pq.pop();

            long long cost = top[0];
            int node = (int)top[1];
            int stops = (int)top[2];

            if (node == dst)
                return (int)cost;

            if (stops > k)
                continue;

            for (int i = 0; i < adj[node].size(); i++) {

                int neigh = adj[node][i].first;
                int price = adj[node][i].second;

                long long newCost = cost + price;

                if (newCost < dist[neigh][stops + 1]) {

                    dist[neigh][stops + 1] = newCost;

                    pq.push(vector<long long>{
                        newCost,
                        (long long)neigh,
                        (long long)(stops + 1)
                    });
                }
            }
        }

        return -1;
    }
};