/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void solve(TreeNode* root, vector<vector<int>> &ans){
        if(root == NULL)return;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int>level; 
            for(int i = 0 ; i < n ; i ++){
              root = q.front();
              q.pop();
              if(root->left) q.push(root->left);
              level.push_back(root->val);
              if(root->right) q.push(root->right);
            }
            ans.push_back(level);
       }
         reverse(ans.begin(),ans.end());
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        solve(root , ans);
        return ans;
    }
};