class Solution {
public:
    void solve(vector<vector<int>>& result, vector<int>& nums, map<vector<int>, bool>& mp, vector<int> temp,  int n ){
        if(n < 0){
            if(!mp[temp]){
                result.push_back(temp);
            }
                mp[temp] = true;
            
            return;
        }
        
        temp.push_back(nums[n]);
        solve(result, nums, mp, temp, n-1);
        temp.pop_back();
        solve(result, nums, mp, temp, n-1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>, bool> mp;
        vector<vector<int>> result;
        vector<int> temp;
        
        sort(nums.begin(), nums.end());
        solve(result, nums, mp, temp, nums.size()-1);
        return result;
    }
};