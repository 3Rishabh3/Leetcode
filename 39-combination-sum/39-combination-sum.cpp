class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, vector<int> temp, int target, int n){
        if(target  == 0){
            ans.push_back(temp);
            return;
        }
        
        if(n < 0)
            return;
        
        if(target-candidates[n] >= 0){
            temp.push_back(candidates[n]);
            solve(candidates, temp, target-candidates[n], n);
            temp.pop_back();
            solve(candidates, temp, target, n-1);
        }
        else
            solve(candidates, temp, target, n-1);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans = vector<vector<int>> ();
        vector<int> temp;
        solve(candidates, temp, target, candidates.size()-1);
        return ans;
    }
};