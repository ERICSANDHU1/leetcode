class Solution {
public:
    // finds FIRST (leftmost) occurrence
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans = mid;        // record this, but keep searching LEFT
                high = mid - 1;   // push left
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }
    // finds LAST (rightmost) occurrence
    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans = mid;        // record this, but keep searching RIGHT
                low = mid + 1;   // push right
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return { findFirst(nums, target), findLast(nums, target) };
    }
};