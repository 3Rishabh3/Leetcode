class Solution {
public:
    bool solve(vector<int>& nums, int n, int target, int sum, int k, vector<bool>& visited){
        if(k == 1)
            return true;
        
        if(n < 0 or sum < 0)
            return false;
        
        if(sum == 0)
            return solve(nums, nums.size()-1, target, target, k-1, visited);
        
        bool flag;
        if(nums[n] > sum or visited[n])
            return solve(nums, n-1, target, sum, k, visited);
        
        else{
            visited[n] = true;
            flag = solve(nums, n-1, target, sum-nums[n], k, visited);
            
            visited[n] = false;
            flag = flag or solve(nums, n-1, target, sum, k, visited);
        }
        
        return flag;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int n : nums)
            sum += n;
        
        if(sum % k != 0)
            return false;
        
        int n = nums.size();
        int target = sum/k;
        vector<bool> visited(n+1, false);
        return solve(nums, n-1, target, target, k, visited);
    }
};