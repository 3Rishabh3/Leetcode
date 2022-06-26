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
    int maxDepth(TreeNode* root){
        if(!root) 
            return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    void solve(TreeNode* root, int& maxd, int& ans, int currd){
        if(!root)
            return;
        if(currd == maxd-1)
            ans += root->val;
        
        solve(root->left, maxd, ans, currd+1);
        solve(root->right, maxd, ans, currd+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        int maxd = maxDepth(root);
        solve(root, maxd, ans, 0);
        return ans;
    }
};