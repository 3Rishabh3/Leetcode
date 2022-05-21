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
    int maxIndex(vector<int>& nums, int i, int j){
        int maxi = i;
        while(++i <= j)
            maxi = nums[i] > nums[maxi] ? i : maxi;
        
        return maxi;
    }
    
    TreeNode* solve(vector<int>& nums, int i, int j){
        if(i > j or i<0 or j > nums.size())
            return NULL;
        
        int idx  = maxIndex(nums, i, j);
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = solve(nums, i, idx-1);
        root->right = solve(nums, idx+1, j);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};