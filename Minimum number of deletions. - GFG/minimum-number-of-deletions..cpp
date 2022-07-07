// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends


int lcs(string& str1, string& str2, int m, int n, vector<vector<int>>& dp){
    if(m == 0 or n == 0)
        return 0;
    
    if(dp[m][n] != -1)
        return dp[m][n];
    
    if(str1[m-1] == str2[n-1])
        return dp[m][n] = 1 + lcs(str1, str2, m-1, n-1, dp);
    
    return dp[m][n] = max(lcs(str1, str2, m-1, n, dp), lcs(str1, str2, m, n-1, dp));    
}

int minDeletions(string str, int n) { 
    //complete the function here
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    string str1 = str;
    reverse(str.begin(), str.end());
    return n-lcs(str1, str, str1.length(), str.length(), dp);
} 