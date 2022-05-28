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
public:
    int currSum;
    void solve(TreeNode* root){
        if(!root)
            return;
        
        solve(root->right);
        currSum += root->val;
        root->val = currSum;
        solve(root->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int > v;
        int i = 0;
        currSum = 0;
        solve(root);
        
        return root;
    }
};