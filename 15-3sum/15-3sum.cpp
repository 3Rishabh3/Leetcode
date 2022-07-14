class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<nums.size()-2; i++){
            if(i == 0 or (i > 0 and nums[i] != nums[i-1])){
                int low = i+1;
                int high = nums.size()-1;
                while(low < high){
                    int a = nums[i], b = nums[low], c = nums[high];
                    int sum = a + b + c;
                    if(sum == 0){
                        ans.push_back({a, b, c});
                        while(low < high and nums[low] == nums[low+1]) low++;
                        while(low < high and nums[high] == nums[high-1]) high--;
                        
                        low++;
                        high--;
                    }
                    else if(sum < 0){
                        low++;
                    }
                    else
                        high--;
                }
            }
        }
        
        return ans;
    }
};