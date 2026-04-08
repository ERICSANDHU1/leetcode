class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> maxD;
        deque<int> minD;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            while(!maxD.empty() && nums[right] > maxD.back())
                maxD.pop_back();

            while(!minD.empty() && nums[right] < minD.back())
                minD.pop_back();

            maxD.push_back(nums[right]);
            minD.push_back(nums[right]);

            while(maxD.front() - minD.front() > limit) {

                if(nums[left] == maxD.front())
                    maxD.pop_front();

                if(nums[left] == minD.front())
                    minD.pop_front();

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};