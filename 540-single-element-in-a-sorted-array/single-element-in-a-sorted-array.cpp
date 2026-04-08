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
       int n = nums.size();
       if(n == 1)return nums[0];
       if(nums[0] != nums[1]) return nums[0];
       if(nums[n-1] != nums[n-2]) return nums[n-1];

       int low = 1 ; 
       int high = n -2;
       while(low <= high){
         int mid = (low + high) / 2;
         if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
            return nums[mid];
         }
         if((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])){
            low = mid + 1;
         }
         else{
            high = mid - 1;
          }
       }
       return -1;
    }
};