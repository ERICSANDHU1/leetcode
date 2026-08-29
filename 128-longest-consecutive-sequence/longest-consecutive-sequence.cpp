class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        for(int i = 0 ; i < n ; i ++){
         st.insert(nums[i]);
        }
            int ans = 0 ; 
          for(int num : st){
          if(st.find(num-1) == st.end()){
            int count = 1; 
            while(st.find(num + 1) != st.end()){
                num++;
                count ++ ; 
            }
            ans = max(ans,count);
          }
        }
        return ans;
    }
};