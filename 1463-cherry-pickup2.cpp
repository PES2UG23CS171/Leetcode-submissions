class Solution {
public:
    int picker(int r, int c1, int c2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& mem, int (&dir)[3]) {
        if(c1<0 || c2<0 || c1>=m || c2>=m)
            return -1;
        if(mem[r][c1][c2] != INT_MIN)
            return mem[r][c1][c2];
        if(r==n-1) {
            if(c1==c2)
                return grid[r][c1];
            return grid[r][c1]+grid[r][c2];
        }
        int c=INT_MIN;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++)
                c=max(c, picker(r+1, c1+dir[i], c2+dir[j], n, m, grid, mem, dir));
        }
        if(c==INT_MIN || c==-1) {
            mem[r][c1][c2]=-1;
            return -1;
        }
        if(c1!=c2)
            c+=grid[r][c1]+grid[r][c2];
        else
            c+=grid[r][c1];
        mem[r][c1][c2]=c;
        return c;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<vector<int>>> mem(n, vector<vector<int>> (m, vector<int> (m, INT_MIN)));
        int dir[3]={-1, 0, 1};
        return picker(0, 0, m-1, n, m, grid, mem, dir);
    }
};
