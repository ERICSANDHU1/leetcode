class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s, ans;

        for(int i = 0 ; i < nums1.size();i++){
            s.insert(nums1[i]);
        }
        for(int j = 0 ; j < nums2.size();j++){
            if(s.count(nums2[j])){
                ans.insert(nums2[j]);
            }
        }
        vector<int> res(ans.begin(),ans.end());
        return res;
    }
};