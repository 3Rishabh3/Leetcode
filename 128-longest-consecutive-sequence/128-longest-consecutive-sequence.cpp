class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        unordered_map<int, int> ump(nums.size());
        int ans = 1;
        for(int n : nums)
            ump[n] = 1;
        
        for(int n : nums){
            int i = n+1;
            int j = n-1;
            while(ump[i] == 1 or ump[j] == 1){
                if(ump[i] == 1){
                    ump[n] += 1;
                    ump[i] = ump[n];
                    ++i;
                }
                if(ump[j] == 1){
                    ump[n] += 1;
                    ump[j] = ump[n];
                    --j;
                }
                
                if(ump[i] == 0 and ump[j] == 0){
                    cout<<n<<","<<i<<","<<j<<endl;
                    break;
                }
            }
            ans = max(ans, i-j-1);
        }
        return ans;
    }
};