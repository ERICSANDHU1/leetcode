class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        //sw + map lgate h 
        int n = nums.size();
        unordered_map<int,int>mp;
        int l = 0 , r = 0, unique = 0 , valid= 0 , extra = 0;
        long long ans = 0;

        while(r<n){
            mp[nums[r]]++;//nyi value ayi h 

            if(mp[nums[r]] == 1){
                unique++; // distinct aa gya 
            }

            if(mp[nums[r]]==m){
                valid++;//freq meet ho gyi 
            }

            //shrink krenge ab 
            while(unique>k){
                //zyda unique aa gye 
                if(mp[nums[l]] == m){
                    valid--;
                }

                mp[nums[l]]--;

                if(mp[nums[l]] == 0){
                    unique--;
                }

                l++; //window choti krdo 
                extra = 0;
            }

            //edge case check kre h 

            while(unique == k&& valid == k && mp[nums[l]]>m){
                mp[nums[l]]--; // window choti kro
                l++;
                extra++;
            }

            if(unique == k && valid == k){
                ans += extra +1;
            }
            
            r++;
        }
        return ans;
        
    }
};