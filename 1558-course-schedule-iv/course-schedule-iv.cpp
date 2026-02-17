class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>indeg(numCourses,0);
        unordered_map<int,vector<int>> adj;

        for(int i = 0 ; i < prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        unordered_map<int,unordered_set<int>>mp;
        for(int i = 0 ; i < numCourses ; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto &nbr : adj[node]){
                    mp[nbr].insert(node);
                 for(auto &preq : mp[node]){
                    mp[nbr].insert(preq);
                 }
                 indeg[nbr]--;
                 if(indeg[nbr] == 0){
                    q.push(nbr);
                  }
                }
            }
        int Q = queries.size();
        vector<bool>result(Q,false);

        for(int i = 0 ; i < Q ; i ++){
            int src = queries[i][0];
            int des = queries[i][1];
             bool isReachable = mp[des].contains(src);
            result[i] = isReachable;
        }
        return result;
    }
};