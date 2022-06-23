// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int, int> p1, pair<int, int> p2){
        return p1.second < p2.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        int count = 0;
        vector<pair<int, int>> v(n);
        pair<int, int> temp = {0, 0};
        for(int i = 0; i<n; i++)
            v[i] = {start[i], end[i]};
        
        sort(v.begin(), v.end(), comp);
        
        for(int i = 0; i<v.size(); i++){
            if(temp.second < v[i].first){
                count++;
                temp = v[i];
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends