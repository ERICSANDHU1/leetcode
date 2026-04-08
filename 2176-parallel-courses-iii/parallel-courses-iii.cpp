class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
       vector<vector<int>> adj(n);
       vector<int>indeg(n,0);
     for(int i = 0 ; i < relations.size();i++){
       int u = relations[i][0] - 1;
       int v = relations[i][1] - 1;
       adj[u].push_back(v);
       indeg[v]++;
     }
       queue<int>q;

       for(int i = 0 ; i < n ; i ++){
        if(indeg[i] == 0){
            q.push(i);
          }
        }
        vector<int>coursetime(n,0);

        for(int i = 0 ; i < n ; i++){
            coursetime[i] = time[i];
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int j = 0 ; j < adj[node].size();j++){
                coursetime[adj[node][j]] = max(coursetime[adj[node][j]],coursetime[node] + time[adj[node][j]]);
                indeg[adj[node][j]]--;
                if(indeg[adj[node][j]]== 0){
                    q.push(adj[node][j]);
                }
            }
       }
       int ans = 0;
       for(int i = 0 ; i < n ; i ++){
        ans = max(ans,coursetime[i]);
       }
        return ans;
    }
};