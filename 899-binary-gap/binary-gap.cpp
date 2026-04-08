class Solution {
public:
    int binaryGap(int n) {
        int lastPos = -1;
        int maxGap = 0;
        int pos = 0;
        
        while (n > 0) {
            if (n & 1) {  // if current bit is 1
                if (lastPos != -1) {
                    maxGap = max(maxGap, pos - lastPos);
                }
                lastPos = pos;
            }
            
            n >>= 1;   // shift right
            pos++;
        }
        
        return maxGap;
    }
};