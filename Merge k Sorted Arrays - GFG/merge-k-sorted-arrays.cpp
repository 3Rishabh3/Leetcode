// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    void Merge(vector<int>& arr1, vector<int> arr2){
        int i = 0;
        int j = 0;
        vector<int> ans;
        
        while(i < arr1.size() and j < arr2.size()){
            if(arr1[i] <= arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }
                
            else{
                ans.push_back(arr2[j]);
                j++;
            }
        }
        while(i < arr1.size()){
            ans.push_back(arr1[i]);
            i++;
        }
        while(j < arr2.size()){
            ans.push_back(arr2[j]);
            j++;
        }
        
        arr1 = ans;
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans = arr[0];
        for(int i = 1; i<K; i++){
            Merge(ans, arr[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends