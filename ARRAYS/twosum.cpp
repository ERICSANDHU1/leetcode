#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {2, 100, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1];
    } else {
        cout << "No solution found";
    }

    return 0;
}