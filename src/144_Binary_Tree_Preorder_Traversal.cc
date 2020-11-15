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



// second try
// 2020-11-15
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        
        stack<TreeNode*> s;
        s.push(root);
        
        TreeNode* top;
        while (!s.empty()) {
            top = s.top();
            s.pop();
            
            res.push_back(top->val);
            
            if (top->right != nullptr) s.push(top->right);
            if (top->left != nullptr) s.push(top->left);
        }
        
        return res;
    }
};
