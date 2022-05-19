class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            int j = i;
            while(i<nums.size() && nums[i]){
                ++i;
                ans = max(ans, i-j);
            }
        }
        
        return ans;
    }
};