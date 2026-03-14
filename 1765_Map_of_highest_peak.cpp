class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) 
    {
        int n=mat.size(), m=mat[0].size();
        queue<int> next;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==1)
                {
                    mat[i][j]=0;
                    next.push(i*m+j);
                }
                else
                    mat[i][j]=INT_MAX;
            }
        }
        int dir[4][2]={{1,0}, {0,1}, {-1, 0}, {0,-1}};
        while(!next.empty())
        {
            int num=next.front();
            int x=num/m, y=num%m;
            next.pop();
            for(const auto& [i, j]: dir)
            {
                int r=x+i, c=y+j;
                if(r<n && c<m && r>-1 && c>-1 && mat[r][c]>mat[x][y]+1)
                {
                    next.push(r*m+c);
                    mat[r][c]=mat[x][y]+1;
                }
            }
        }
        return mat;
    }
};
