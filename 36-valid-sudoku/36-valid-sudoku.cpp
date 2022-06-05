class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, grid[3][3][9]={0};
        
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.')
                {
                    int idx = board[i][j] - '0' - 1;
                    if(row[i][idx] || col[j][idx] || grid[i/3][j/3][idx])
                        return false;
                    row[i][idx] = col[j][idx] = grid[i/3][j/3][idx] = 1;
                }
            }
        }
        return true;
    }
};