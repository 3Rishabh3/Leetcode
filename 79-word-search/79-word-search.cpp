class Solution {
public:
    
    bool solve(vector<vector<char>>& board, string word, int row, int col){
        
        if(!word.size())
            return true;
        
        if(row >= board.size() or row < 0 or col >= board[0].size() or col < 0 or board[row][col] != word[0])
            return false;
        
            char ch = board[row][col];
            board[row][col] = '*';
            string s = word.substr(1);
            bool a = solve(board, s, row-1, col);
            bool b = solve(board, s, row, col+1);
            bool c = solve(board, s, row+1, col);
            bool d = solve(board, s, row, col-1);
            board[row][col] = ch;
        
        return a or b or c or d;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(solve(board, word, i, j))
                    return true;
            }
        }
        
        return false;
    }
};