class Solution {
public:
    string largestGoodInteger(string num) {

        string ans = "";

        for (int i = 0; i < num.size() - 2; i++) {

            // Check 3 consecutive same digits
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {

                string curr = num.substr(i, 3);

                // If this is the first valid group
                // or curr is bigger than ans
                if (ans == "" || curr > ans) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};