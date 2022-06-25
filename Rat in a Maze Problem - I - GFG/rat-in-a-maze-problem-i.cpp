// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<vector<int>> &board, int n, vector<string>& ans, string s, int i, int j, vector<vector<bool>> visited){
        if(i < 0 or i >= n or j < 0 or j >= n or visited[i][j] == true or board[i][j] == 0)
            return;
        
        if(i == n-1 and j == n-1){
            ans.push_back(s);
            return;
        }
        

        visited[i][j] = true;
        solve(board, n, ans, s+"U", i-1, j, visited);
        solve(board, n, ans, s+"R", i, j+1, visited);
        solve(board, n, ans, s+"D", i+1, j, visited);
        solve(board, n, ans, s+"L", i, j-1, visited);
        visited[i][j] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &board, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        solve(board, n, ans, "", 0, 0, visited);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends