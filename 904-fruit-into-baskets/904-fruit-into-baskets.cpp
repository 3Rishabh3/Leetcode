class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> ump;
        
        int ans = 0;
        for(int i = 0, j = 0; j<fruits.size(); j++){
            ump[fruits[j]]++;
            while(ump.size() > 2){
                if(--ump[fruits[i]] == 0){
                    ump.erase(fruits[i]);
                }
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};