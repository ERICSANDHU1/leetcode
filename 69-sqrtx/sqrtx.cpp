class Solution {
public:
    int mySqrt(int x) {
        int low =  0 ; 
        int high = x ; 
        int ans = 0 ; 
        while(low <= high){
            double mid = (low + high) / 2;
            if((mid * mid) <= x){
                ans = mid;
                low = low + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};