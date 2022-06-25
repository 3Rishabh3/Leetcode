class Solution {
public:
    
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool> (s.length()));
        int length=0,start;
        
        for(int g = 0; g<s.length(); g++){
            int i = 0;
            int j = g;
            
            while(j < s.length()){
                if(g == 0){
                    dp[i][j] = true;
                }
                else if(g == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }
                }
                else{
                    if(s[i] == s[j] and dp[i+1][j-1]){
                        dp[i][j] = true;
                    }
                }
                if(dp[i][j]==true){
                    length=g+1;
                    start=i;
                }
                i++;
                j++;
            }
        }
        return s.substr(start,length);
    }
};