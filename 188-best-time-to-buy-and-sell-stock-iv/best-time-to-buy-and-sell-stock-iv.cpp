class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> ERIClovesVANSHIKA(
            n+1, vector<vector<int>>(2, vector<int>(k+1,0))
        );

        for(int i = n-1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int cap = 1 ; cap <= k ; cap++){

                    if(buy){
                        ERIClovesVANSHIKA[i][buy][cap] =
                        max(-prices[i] + ERIClovesVANSHIKA[i+1][0][cap],
                            ERIClovesVANSHIKA[i+1][1][cap]);
                    }
                    else{
                        ERIClovesVANSHIKA[i][buy][cap] =
                        max(prices[i] + ERIClovesVANSHIKA[i+1][1][cap-1],
                            ERIClovesVANSHIKA[i+1][0][cap]);
                    }

                }
            }
        }

        return ERIClovesVANSHIKA[0][1][k];
    }
};