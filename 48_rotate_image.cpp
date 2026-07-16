class Solution {
public:
    void rotate(vector<vector<int>>& M) {
        for(int i=0; i<M.size(); i++) {
            for(int j=i+1; j<M.size(); j++) {
                int t=M[i][j];
                M[i][j]=M[j][i];
                M[j][i]=t;
            }
            reverse(M[i].begin(), M[i].end());
            // reverse(M.begin(), M.end()); reverses order of rows
        }
    }
};
 
 /*
1 2 3
4 5 6
7 8 9

R180- rev(rows)+rev(matrix row order)
9 8 7
6 5 4
3 2 1

R270- T+reverse col
3 6 9
2 5 8
1 4 7

T
1 4 7
2 5 8
3 6 9
*/
