class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), g=n*m-1, l=(n+m)/2;
        vector<vector<bool>> seen(g+1, vector<bool> (l+1, false));
        if(grid[0][0]==')' || grid[n-1][m-1]=='(')
            return false;
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        while(!Q.empty()) {
            auto [x, b]=Q.front();
            Q.pop();
            int r=x/m, c=x%m;
            if(grid[r][c]==')')
                b--;
            else
                b++;
            if(b<0 || b>l) continue;
            if(x==g && b==0) return true;
            if(r+1<n && !seen[x+m][b]) {
                Q.push({x+m, b});
                seen[x+m][b]=true;
            }
            if(c+1<m && !seen[x+1][b]) {
                Q.push({x+1, b});
                seen[x+1][b]=true;
            }     
        }
        return false;
    }
};
