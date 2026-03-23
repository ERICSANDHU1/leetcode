class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int left = 0 ; 
        int countW = 0;
        int minlen = INT_MAX;

        for(int right = 0 ; right < n ; right ++){
            if(blocks[right] == 'W') countW ++;

            while(right - left + 1 == k){
                minlen = min(minlen,countW);
                if(blocks[left] == 'W') countW--;
                left ++;
            } 
        }
        return minlen;
    }
};