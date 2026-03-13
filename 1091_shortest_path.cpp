class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        vector<vector<int>> dir={{1,1}, {0,1}, {1,0}, {-1, 0}, {-1, -1}, {0, -1}, {1,-1}, {-1,1}};
        vector<vector<int>> seen(n, vector<int> (n, 0));
        seen[0][0]=1;
        queue<pair<int, int>> next;
        next.push({0,0});
        while(!next.empty())
        {
            int r=next.front().first, c=next.front().second;
            if(r==n-1 && c==n-1)
                return seen[r][c];
            next.pop();
            for(const auto& x: dir)
            {
                int rn=r+x[0], cn=c+x[1];
                if(rn<n && rn>-1 && cn>-1 && cn<n && grid[rn][cn]==0 && seen[rn][cn]==0)
                {
                    next.push({r+x[0], c+x[1]});
                    seen[rn][cn]=seen[r][c]+1;
                }
            }
        }
        return -1;
    }
};
