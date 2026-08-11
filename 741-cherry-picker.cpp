class Solution {
public:
    int picker(int r1, int r2, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& mem, int n) {
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return -1;
        if(mem[r1][r2][c1] != INT_MIN)
            return mem[r1][r2][c1];
        if(r1==n-1 && r2==n-1 && c1==n-1 && c2==n-1)
            return grid[n-1][n-1];
        int c=max({picker(r1+1, r2+1, c1, c2, grid, mem, n), 
                   picker(r1+1, r2, c1, c2+1, grid, mem, n),
                   picker(r1, r2+1, c1+1, c2, grid, mem, n),
                   picker(r1, r2, c1+1, c2+1, grid, mem, n)});
        // INT_MIN: unvisited, -1: visited but solution not possible
        if(c==INT_MIN || c==-1) {
            mem[r1][r2][c1]=-1;
            return -1;
        }
        c+=grid[r1][c1];
        if(r1!=r2 && c1!=c2)    
            c+=grid[r2][c2];
        mem[r1][r2][c1]=c;
        return c;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> mem(n, vector<vector<int>> (n, vector<int> (n, INT_MIN)));
        // only 3 dim as r1+c1=r2+c2 as both are moving only 1 step at a time
        return max(0, picker(0, 0, 0, 0, grid, mem, n));
    }
};
