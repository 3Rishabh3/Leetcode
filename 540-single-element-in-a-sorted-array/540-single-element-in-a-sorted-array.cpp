class Solution {
public:
    int solve(vector<int>& nums, int low, int high){
        if(low > high)
            return -1;
        
        int mid = low + (high - low)/2;
        if(mid-1 >= 0 && mid+1 < nums.size() && nums[mid-1] < nums[mid] and nums[mid] < nums[mid+1]){
            return nums[mid];
        }
        
        int y = -1;
        int x = solve(nums, low, mid-1);
        if(x == -1)
             y = solve(nums, mid+1, high);
        
        return x != -1 ? x : y;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int ans = solve(nums, 0, nums.size()-1);
        if(ans == -1){
            if(nums[0] != nums[1])
                return nums[0];
            else if(nums.back() != --nums.back())
                return ++nums.back();
        }
        return ans;
    }
};