class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        vector<vector<int>> move={{0,1}, {0,-1}, {1,0}, {-1,0}};
        int ans=0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j])
                {
                    grid[i][j]=0;
                    int arr=1;
                    area(grid, move, i, j, arr);
                    ans=max(ans, arr);
                }
            }
        }
        return ans;
    }
    void area(vector<vector<int>>& grid, vector<vector<int>>& move, int r, int c, int& A)
    {
        for(const auto& x: move)
        {
            int i=r+x[0], j=c+x[1];
            if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j])
            {
                A++;
                grid[i][j]=0;
                area(grid, move, i, j, A);
            }
        }
    }
};
