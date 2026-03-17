class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        for(auto& it : freq){        // ✅ iterate map correctly
            if(it.second == 1)       // ✅ check value directly
                return it.first;     // ✅ return the key
        }

        return -1;                   // ✅ valid return
    }
};