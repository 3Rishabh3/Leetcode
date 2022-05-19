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
    void solve(TreeNode* root, map<int, multiset<pair<int, int>>>& mp, int i, int j){
        if(!root)
            return;
        
        solve(root->left, mp, i-1, j+1);
        mp[i].insert({j, root->val});
        solve(root->right, mp, i+1, j+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int, int>>> mp;
        vector<vector<int>> ans;
        
        solve(root, mp, 0, 0);
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            vector<int> temp;
            for(auto i : itr->second){
                temp.push_back(i.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};