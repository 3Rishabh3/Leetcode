class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int maxReach = 0;
        int curr = -1;
        for(int i = 0; maxReach < nums.size()-1; i++){
            if(i > curr){
                ans++;
                curr = maxReach;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        
        return ans;
    }
};