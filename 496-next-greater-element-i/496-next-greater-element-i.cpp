class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> ump;
        
        for(int i = nums2.size()-1; i >= 0; i--){
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }
            if(st.empty())
                ump[nums2[i]] = -1;
            else
                ump[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }
        
        for(int n : nums1)
            ans.push_back(ump[n]);
        
        return ans;
    }
};