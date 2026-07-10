class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return Atmost(nums,k) - Atmost(nums,k-1);
    }
    int Atmost(vector<int>& nums, int k){
        unordered_map<int,int> freq;
        int left = 0 ;
        int right = 0 ; 
        int n = nums.size();
        int maxlength = 0 ; 
        int count = 0 ; 

        if(k < 0 ) return 0 ; 

        while( right < n ){
            if(freq[nums[right]] == 0) count ++;
             freq[nums[right]]++;

         while( count > k ){
            freq[nums[left]]--;
           if(freq[nums[left]] == 0) count --;
            left ++;
         }
         maxlength += (right - left + 1);
         right ++;
        }
        return maxlength;
    }
};