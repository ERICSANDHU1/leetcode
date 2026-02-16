class Solution {
public:
   vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
       vector<vector<int>> result(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(isWater[i][j] == 1){ // in 01 matrix question this was isWater[i][j] == 0 
                    result[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;

            for(auto &dir : directions){
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i >= 0 && new_j >= 0 && new_i < n && new_j < m && result[new_i][new_j] == -1){
                    result[new_i][new_j] = result[i][j] + 1;
                    q.push({new_i,new_j});
                }
            }
        }
        return result;
    }
};