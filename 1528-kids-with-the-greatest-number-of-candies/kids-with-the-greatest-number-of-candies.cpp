class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxval = INT_MIN;
        vector<bool>result;
        for(int i = 0 ; i < n ; i ++){
            maxval = max(maxval,candies[i]);
        }
        for(int i = 0 ; i < n ; i ++){
            int extra = candies[i] + extraCandies;
            result.push_back(extra >= maxval);
        }
        return result;
    }
};