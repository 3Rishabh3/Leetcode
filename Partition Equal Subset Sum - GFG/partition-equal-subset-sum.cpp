// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool solve(int n, int arr[], int k){
        if(k == 0)
            return true;
        if(k < 0 or n == 0)
            return false;
        
        if(k-arr[n-1] >= 0)
            return solve(n-1, arr, k-arr[n-1]) or solve(n-1, arr, k);
        
        return solve(n-1, arr, k);    
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i<N; i++)
            sum += arr[i];
            
        if(sum % 2 != 0)
            return 0;
            
        return solve(N, arr, sum/2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends