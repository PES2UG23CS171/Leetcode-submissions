class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            vector<bool> row(9, false), col(9, false);
            for(int j=0; j<9; j++) {
                if(board[j][i]=='.')
                    goto next;
                if(col[board[j][i]-'1']==true)
                    return false;
                col[board[j][i]-'1']=true;

                next:
                if(board[i][j]=='.')
                    continue;
                if(row[board[i][j]-'1']==true)
                    return false;
                row[board[i][j]-'1']=true;
            }
        }
        for(int l=0; l<3; l++) {
            for(int i=0; i<3; i++) {
                vector<bool> dig(9, false);
                int r=3*l, c=3*i;
                for(int j=0; j<3; j++) {
                    for(int k=0; k<3; k++) {
                        if(board[r+j][c+k]=='.')
                            continue;
                        if(dig[board[r+j][c+k]-'1']==true)
                            return false;
                        dig[board[r+j][c+k]-'1']=true;
                    }
                }
            }
        }
        return true;
    }
};
