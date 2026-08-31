class Solution {
public:
    int calc(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j) {
        if(mem[i][j]!=-1)
            return mem[i][j];
        int m=grid.size(), n=grid[0].size(), ans=INT_MAX;
        if(i==m-1 && j==n-1)
            return grid[i][j];
        if(i+1<m)
            ans=calc(grid, mem, i+1, j);
        if(j+1<n)
            ans=min(ans, calc(grid, mem, i, j+1));
        mem[i][j]=ans+grid[i][j];
        return mem[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> mem(m, vector<int> (n, -1));
        return calc(grid, mem, 0, 0);
    }
};
