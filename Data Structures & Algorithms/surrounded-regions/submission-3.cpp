class Solution {
    int rows,cols;
public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        for(int i = 0;i<rows;i++)
        {
            if(board[i][0] == 'O')
            {
                capture(board,i,0);//capture the unsorrounded region 
            }
            if(board[i][cols-1] == 'O')
            {
                capture(board,i,cols-1);
            }
        }
        for(int i = 0;i<cols;i++)
        {
            if(board[0][i] == 'O')
            {
                capture(board,0,i);//capture the unsourrounded 
            }
            if(board[rows-1][i] == 'O')
            {
                capture(board,rows-1,i);
            }
        }

        for(int i = 0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void capture(vector<vector<char>>& board, int r, int c)
    {
        if(r<0 || r>=rows || c<0 || c>=cols || board[r][c]!='O') {return;}
        board[r][c]='T';
        capture(board,r+1,c);
        capture(board,r-1,c);
        capture(board,r,c+1);
        capture(board,r,c-1);
    }
};
