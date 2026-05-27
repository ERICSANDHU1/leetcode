class Solution {
public:
    int reverse(int x) {
        int revNum = 0;
        while (x != 0) {
            int ld = x % 10;
            x /= 10;

            // Check for overflow before multiplying
            if (revNum > INT_MAX/10 || revNum < INT_MIN/10) {
                return 0;
            }

            revNum = revNum * 10 + ld;
        }
        return revNum;
    }
};