class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                low = mid;
                high = mid;
                for(int i = mid; i >= 0; i--)
                    if(nums[i] == nums[mid])
                        low--;
                for(int i = mid; i < nums.size(); i++)
                    if(nums[i] == nums[mid])
                        high++;
                
                return {low+1, high-1};
            }
                
            if(nums[mid] > target)
                high = mid-1;
            
            else
                low = mid+1;
        }
        
        return {-1, -1};
    }
};