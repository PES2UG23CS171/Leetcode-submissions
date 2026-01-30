class Solution {
public:
    bool exist(vector<vector<char>>& board, string Q) 
    {
        bool ans=false;
        int move[4][2]={{0,-1}, {-1, 0}, {0, 1}, {1,0}};
        for(int i=0; i<board.size() && !ans; i++)
            for(int j=0; j<board[0].size() && !ans; j++)
                if(board[i][j]==Q[0])
                {
                    board[i][j]='\0';
                    back(board, Q, 1, ans, i, j, move);
                    board[i][j]=Q[0];
                }
        return ans;
    }
    void back(vector<vector<char>>& board, string& Q, int curr, bool& ans, int r, int c,int (&move)[4][2])
    {
        if(curr==Q.size() || ans)
        {
            ans=true;
            return;
        }
        for(const auto m: move)
        {
            int x= r + m[0];
            int y= c + m[1];
            if(x<board.size() && x>-1 && y>-1 && y<board[0].size() && board[x][y]==Q[curr])
            {
                
                board[x][y]='\0';
                back(board, Q, curr+1, ans, x, y, move);
                board[x][y]=Q[curr];
            }
        }
    }
};
