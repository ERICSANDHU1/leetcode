class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int answer = 0;
        unordered_map<int,int>mp;

        for(int i = 0 ; i < n ; i++){
            int rem = time[i] % 60 ; 
            int comple = (60 - rem) % 60;
            answer += mp[comple];
            mp[rem]++;
        }
        return answer;
    }
};