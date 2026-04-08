class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visit(V,-1);
        queue<int>q;
        for(int i = 0 ; i < V ; i ++){
            if(visit[i] == -1){
                q.push(i);
                visit[i] = 0 ; 

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int j = 0 ; j < graph[node].size(); j ++){
                        if(visit[graph[node][j]] == -1){
                            visit[graph[node][j]] = (visit[node]+1) % 2;
                            q.push(graph[node][j]);
                        } 
                        else{
                            if(visit[graph[node][j]] == visit[node]) return 0 ; 
                        }
                    }
                }
            }

        }
        return 1;

    }
};