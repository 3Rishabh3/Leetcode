class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int j = 0;
        for(int i = 0; i<nums.size(); i++){
            while(i<nums.size() && nums[i] == nums[j]){
                i++;
            }
            if(i==nums.size()) break;
            ++k;
            nums[k] = nums[i];
            j = i;
        }
        
        return k+1;
    }
};