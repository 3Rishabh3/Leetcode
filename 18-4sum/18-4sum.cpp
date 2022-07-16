class Solution {
public:
    
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                    int low = j+1, high = n-1;
                    int a = nums[i], b = nums[j];
                    long long target2 = (long long)target - (long long)a - (long long)b;
                    while(low < high){
                        int c = nums[low], d = nums[high];
                        int sum = c + d;
                    
                        if(sum == target2){
                            ans.push_back({a, b, c, d});
                            while(low<high and nums[low] == nums[low+1]) low++;
                            while(low<high and nums[high] == nums[high-1]) high--;
                            
                            low++;
                            high--;
                        }             
                    
                        else if(sum < target2){
                            low++;
                        }
                        else
                            high--;
                    }
                while(j+1<n and nums[j+1] == nums[j]) j++;
            }
            while(i+1<n and nums[i+1] == nums[i]) i++;
        }
        
        return ans;
    }
};