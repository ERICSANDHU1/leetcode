/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
 void dfs(Node* root , vector<vector<int>> &ans){
    if(root == NULL) return ;
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
         int n = q.size();
            vector<int>level;
         for(int i = 0 ; i < n ; i++){
             root = q.front();
             q.pop();
             level.push_back(root->val);
             for(int j = 0 ; j < root->children.size();j++){
             if(root->children[j]) q.push(root->children[j]);
            }
        }
        ans.push_back(level);
    }
 }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        dfs(root,ans);
        return ans;
    }
};