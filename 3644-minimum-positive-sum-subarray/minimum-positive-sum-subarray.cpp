class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        // Prefix Sum
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int ans = INT_MAX;
        // Starting index
        for(int i = 0; i < n; i++) {
            // Length from l to r
            for(int len = l; len <= r; len++) {
                int j = i + len;
                if(j <= n) {
                    int sum = prefix[j] - prefix[i];
                    if(sum > 0) {
                        ans = min(ans, sum);
                    }
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
         return ans;
    }
};