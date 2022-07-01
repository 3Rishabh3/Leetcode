class Solution {
public:
    
    bool solve(vector<int>& nums, int n, int k, vector<vector<int>>& dp){
        if(n <= 0)
            return false;
        
        if (dp[n][k] != -1)
            return dp[n][k];
        
        if(k == 0)
            return true;
        
        if(k - nums[n-1] >= 0)
            return dp[n][k] = solve(nums, n-1, k-nums[n-1], dp) or solve(nums, n-1, k, dp);
        
        return dp[n][k] = solve(nums, n-1, k, dp);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int n : nums)
            sum += n;
        
        vector<vector<int>> dp(nums.size()+1, vector<int> (sum/2 + 1, -1));
        if(sum%2 != 0)
            return false;
        
        return solve(nums, nums.size(), sum/2, dp);
    }
};