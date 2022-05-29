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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode* > q;
        vector<vector<int>> ans;
        q.push(root);
        bool flag = false;
        
        while(!q.empty()){
            int n = q.size();
            vector<int> curr;
            for(int i = 0; i<n; i++){
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                
                curr.push_back(q.front()->val);
                q.pop();
            }
            if(flag)
                reverse(curr.begin(), curr.end());
            ans.push_back(curr);
            flag = !flag;
        }
        return ans;
    }
    
    
    
    
    
    
    
    
};