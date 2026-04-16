class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int>row;
        unordered_map<int,int>col;
        unordered_map<int,int>diag1;
        unordered_map<int,int>diag2;
       
        set<pair<int,int>>st;

        for(int i = 0 ; i < lamps.size(); i++){
           int r = lamps[i][0];
           int c = lamps[i][1];

           if(!st.count({r,c})){
             st.insert({r,c});
             row[r]++;
             col[c]++ ; 
             diag1[r+c]++;
             diag2[r-c]++;
           }
        }
        vector<int>ans;
         vector<vector<int>> directions = {
            {0,0},
            {0,1}, {0,-1}, {1,0}, {-1,0},
            {1,1}, {1,-1}, {-1,1}, {-1,-1}
        };
       for(int i = 0 ; i < queries.size() ; i++){
        int r = queries[i][0];
        int c = queries[i][1];

          if(row[r] > 0 || col[c] > 0 || diag1[r+c] > 0 || diag2[r-c] > 0){
            ans.push_back(1);
          }
          else{
            ans.push_back(0);
          }
          for(int j = 0 ; j < directions.size(); j ++){
            int nr =  r + directions[j][0];
            int nc =  c + directions[j][1];

            if(st.count({nr,nc})){
                st.erase({nr,nc});
                row[nr]--;
                col[nc]-- ; 
                diag1[nr+nc]--;
                diag2[nr-nc]--;
            }
          }
       }
       return ans ; 
    }
};