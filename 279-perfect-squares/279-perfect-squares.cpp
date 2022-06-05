class Solution {
public:
    int solve(vector<int>& squares, int i, int target, vector<vector<int>>& dp){
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        if(target == 0)
            return 0;
        
        if(i == 0)
            return 1e9;
        
        if(target-squares[i] >= 0){
            return dp[i][target] = min(solve(squares, i, target-squares[i], dp)+1, solve(squares, i-1, target, dp));
        }
        return dp[i][target] = solve(squares, i-1, target, dp); 
    }
    
    int numSquares(int n) {
        int size = sqrt(n);
        vector<int> squares(size+1);
        for(int i = 1; i<=size; i++)
            squares[i] = i*i;
        
        vector<vector<int>> dp(size+1, vector<int>(n+1, -1));
        
        return solve(squares, size, n, dp);
    }
};