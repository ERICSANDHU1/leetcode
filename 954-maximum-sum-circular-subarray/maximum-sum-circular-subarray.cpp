class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0 ; 
        int minsum = 0; 
        int maxsum = 0; 
        int currsum = 0; 

        for(int i = 0 ; i < n ; i ++){
            totalsum += nums[i];
            currsum += nums[i];
            if(currsum < 0 ){
                currsum = 0 ; 
            }
            maxsum = max(maxsum,currsum);
        }
           currsum = 0 ; 
       for(int i = 0 ; i < n ; i ++){
        // totalsum += nums[i];
        currsum += nums[i];
        if(currsum > 0 ){
            currsum = 0 ; 
        }
        minsum = min(minsum,currsum);
       }
       // Handle arrays containing only negative numbers
        if (maxsum == 0) {
            return *max_element(nums.begin(), nums.end());
        }
       return max(maxsum,totalsum - minsum);
    }
};