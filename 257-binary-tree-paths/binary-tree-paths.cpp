class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;

        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});

        while(!q.empty()) {
            TreeNode* node = q.front().first;
            string path = q.front().second;
            q.pop();

            // leaf node
            if(node->left == NULL && node->right == NULL) {
                ans.push_back(path);
            }

            if(node->left) {
                q.push({node->left, path + "->" + to_string(node->left->val)});
            }

            if(node->right) {
                q.push({node->right, path + "->" + to_string(node->right->val)});
            }
        }

        return ans;
    }
};
