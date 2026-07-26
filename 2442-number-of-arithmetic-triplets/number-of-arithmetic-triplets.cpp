class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i ++){
         mp[nums[i]] ++;
         }
        int cnt = 0 ; 
        for(int i = 0 ; i < n ; i ++){
           
           int x = nums[i] - diff;
           int y = nums[i] + diff;

           if(mp[x] && mp[y]) cnt ++;
        }
        return cnt;
    }
};