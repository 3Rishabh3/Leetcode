class Solution {
private:
    void NSE(vector<int>& arr, vector<int>& nse){
        stack<int> st;
        
        for(int i = arr.size()-1; i >= 0; i--){
            if(st.empty())
                nse.push_back(arr.size());
            
            else if(!st.empty() and arr[st.top()] < arr[i])
                nse.push_back(st.top());
            
            else if(!st.empty() and arr[st.top()] >= arr[i]){
                while(!st.empty() and arr[st.top()] >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    nse.push_back(arr.size());
                }
                else{
                    nse.push_back(st.top());
                }
            }
            st.push(i);
        }
        
        reverse(nse.begin(), nse.end());
    }
    
    void PSE(vector<int>& arr, vector<int>& pse){
        stack<int> st;
        
        for(int i = 0; i < arr.size(); i++){
            if(st.empty()){
                pse.push_back(-1);
            }
            else if(!st.empty() and arr[st.top()] < arr[i]){
                pse.push_back(st.top());
            }
            else if(!st.empty() and arr[st.top()] >= arr[i]){
                while(!st.empty() and arr[st.top()] >= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    pse.push_back(-1);
                }
                else{
                    pse.push_back(st.top());
                }
            }
            st.push(i);
        }
    }
    
    int MAH(vector<int>& arr){
        vector<int> nse;
        vector<int> pse;
        NSE(arr, nse);
        PSE(arr, pse);
        int ans = 0;
        
        for(int i = 0; i<arr.size(); i++)
            ans = max(ans, abs(nse[i]-pse[i]-1)*arr[i]);
        
        return ans;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<vector<int>> grid(matrix.size(), vector<int>(matrix[0].size(), 1));
        int ans = 0;
        
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '0')
                    grid[i][j] = 0;
            }
        }
        
        for(int i = 1; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j])
                    grid[i][j] += grid[i-1][j];
            }
        }
        
        for(int i = 0; i<grid.size(); i++)
            ans = max(ans, MAH(grid[i]));
        
        return ans;
    }
};