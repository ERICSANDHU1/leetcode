class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int minsum = 0; 
        int maxsum = 0; 
        int currsum = 0; 

        for(int i = 0 ; i < n ; i ++){
            currsum += nums[i];
            if(currsum < 0 ){
                currsum = 0 ; 
            }
            maxsum = max(maxsum,currsum);
        }
           currsum = 0 ; 
       for(int i = 0 ; i < n ; i ++){
        currsum += nums[i];
        if(currsum > 0 ){
            currsum = 0 ; 
        }
        minsum = min(minsum,currsum);
       }
       return max(maxsum,abs(minsum));
    }
};