// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int> freq;

//         for(int i = 0; i < n; i++){
//             freq[nums[i]]++;
//         }

//         for(auto& it : freq){        // ✅ iterate map correctly
//             if(it.second == 1)       // ✅ check value directly
//                 return it.first;     // ✅ return the key
//         }

//         return -1;                   // ✅ valid return
//     }
// };

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;

        while(lo < hi){
            int mid = lo + (hi - lo) / 2;

            // Always make mid even for consistent comparison
            if(mid % 2 == 1) mid--;

            if(nums[mid] == nums[mid + 1])
                lo = mid + 2;   // pair intact → go RIGHT
            else
                hi = mid;       // pair broken → go LEFT (or here)
        }

        return nums[lo];
    }
};