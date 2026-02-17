class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {

        vector<int> pre(n, 0);

        // build prerequisite mask
        for(int i = 0; i < relations.size(); i++) {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;
            pre[v] |= (1 << u);
        }

        int fullMask = (1 << n) - 1;
        vector<int> dp(1 << n, 1e9);
        dp[0] = 0;

        for(int mask = 0; mask <= fullMask; mask++) {

            // find available courses
            int avail = 0;
            for(int i = 0; i < n; i++) {
                if((mask & (1 << i)) == 0 && (mask & pre[i]) == pre[i]) {
                    avail |= (1 << i);
                }
            }

            // count available
            int cnt = __builtin_popcount(avail);

            // if we can take all
            if(cnt <= k) {
                dp[mask | avail] = min(dp[mask | avail], dp[mask] + 1);
            }
            else {
                // generate subsets of avail of size k
                for(int sub = avail; sub > 0; sub = (sub - 1) & avail) {
                    if(__builtin_popcount(sub) == k) {
                        dp[mask | sub] = min(dp[mask | sub], dp[mask] + 1);
                    }
                }
            }
        }

        return dp[fullMask];
    }
};
