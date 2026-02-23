#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        if (n < (1 << k) + k - 1) 
            return false;
        
        unordered_set<string> seen;
        
        for (int i = 0; i <= n - k; i++) {
            seen.insert(s.substr(i, k));
        }
        
        return seen.size() == (1 << k);
    }
};