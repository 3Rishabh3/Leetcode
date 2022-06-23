// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(pair<int, int> p1, pair<int, int> p2){
        return p1.first > p2.first;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        int ans = 0;
        int count = 0;
        int mxDead = 0;
        vector<pair<int, int>> v(n);
        for(int i = 0; i<n; i++){
            v[i] = {arr[i].profit, arr[i].dead};
            mxDead = max(mxDead, arr[i].dead);
        }
        vector<int> slots(mxDead+1);
        sort(v.begin(), v.end(), comp);
        
        for(int i = 0; i<v.size(); i++){
            int dead = v[i].second;
            int profit = v[i].first;
            while(dead > 0){
                if(slots[dead] == true){
                    dead--;
                }
                else{
                    slots[dead] = true;
                    ans += profit;
                    count++;
                    break;
                }
            }
        }
        return {count, ans};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends