class Solution {
public:
    
    void solve(vector<vector<int>>& matrix, vector<int>& ans, int row, int col, int r, int d, int l, int u){
        
        if(row < 0 or row >= matrix.size() or col < 0 or col >= matrix[0].size() or matrix[row][col] == 101){
            return;
        }
        
        if(r){
            while(col < matrix[0].size() and matrix[row][col] != 101){
                ans.push_back(matrix[row][col]);
                matrix[row][col] = 101;
                col++;
            }
            r = 0;
            d = 1;
            --col;
            ++row;
        }
        
        else if(d){
            while(row < matrix.size() and matrix[row][col] != 101){
                ans.push_back(matrix[row][col]);
                matrix[row][col] = 101;
                row++;
            }
            d = 0;
            l = 1;
            --col;
            --row;
        }
        
        else if(l){
            while(col >= 0 and matrix[row][col] != 101){
                ans.push_back(matrix[row][col]);
                matrix[row][col] = 101;
                col--;
            }
            l = 0;
            u = 1;
            ++col;
            --row;
        }
        
        else if(u){
            while(row >= 0 and matrix[row][col] != 101){
                ans.push_back(matrix[row][col]);
                matrix[row][col] = 101;
                row--;
            }
            u = 0;
            r = 1;
            ++col;
            ++row;
        }
        
        solve(matrix, ans, row, col, r, d, l, u);
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int r = 1, d = 0, l = 0, u = 0;
        solve(matrix, ans, 0, 0, r, d, l, u);
        return ans;
    }
};