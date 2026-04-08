class Solution {
public:
long long merge(vector<int>& nums, int low, int mid, int high){
  long long cnt=0;
  int right=mid+1;
  for(int i=low;i<=mid;i++){
     while(right<=high && (long long)nums[i]>2LL* nums[right]){
        right++;
     }
     cnt+=(right-(mid+1));
  }
  vector<int> temp;
  int left = low;
    right = mid + 1;
     while(left <= mid && right <= high) {
        if(nums[left] <= nums[right])
            temp.push_back(nums[left++]);
        else
            temp.push_back(nums[right++]);
    }
    while(left <= mid)  temp.push_back(nums[left++]);
    while(right <= high)  temp.push_back(nums[right++]);
    for(int i = low; i <= high; i++)
        nums[i] = temp[i - low];
    return cnt;
}
long long mergesort(vector<int>& nums, int low, int high){
      if(low >= high) return 0;
    int mid = (low + high) / 2;
    long long cnt = 0;
    cnt += mergesort(nums, low, mid);
    cnt += mergesort(nums, mid + 1, high);
    cnt += merge(nums, low, mid, high);
    return cnt;
}
    int reversePairs(vector<int>& nums) {
        int n =nums.size();
        return mergesort(nums, 0, n - 1);
    }
};