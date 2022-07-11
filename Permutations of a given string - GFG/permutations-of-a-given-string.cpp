// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void solve(string &S, set<string>& ans, int i){
	        if(i == S.length()-1)
	        {
	            ans.insert(S);
	            return;
	        }
	        
	        for(int j = i; j<S.size(); j++){
	            swap(S[i], S[j]);
	            solve(S, ans, i+1);
	            swap(S[i], S[j]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> ans;
		    vector<string> v;
		    
		    solve(S, ans,  0);
		    for(auto i : ans)
		        v.push_back(i);
		        
		    return v;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends