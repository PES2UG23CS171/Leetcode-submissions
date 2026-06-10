class Solution {
public:
    void dfs(vector<vector<int>>& H, vector<vector<bool>>& seen, int r, int c, int n, int m, int v, bool& cond, int (&dir)[4][2])
    {
        if(r==n-1 && c==m-1)
        {
            cond=true;
            return;
        }
        for(const auto& x: dir)
        {
            int xx=r+x[0], yy=c+x[1];
            if(xx>=0 && yy>=0 && xx<n && yy<m && !seen[xx][yy] && abs(H[r][c]-H[xx][yy])<=v && !cond)
            {
                seen[xx][yy]=true;
                dfs(H, seen, xx, yy, n, m, v, cond, dir);
            }
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int r=0, l=0, n=heights.size(), m=heights[0].size();
        for(const auto& v: heights)
            r=max(r, *max_element(v.begin(), v.end()));
        bool cond=false;
        int dir[4][2]= {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(l<r)
        {
            int mid=l+(r-l)/2;
            vector<vector<bool>> seen(n, vector<bool> (m, false));
            seen[0][0]=true;
            dfs(heights, seen, 0, 0, n, m, mid, cond, dir);
            if(cond)
                r=mid;
            else
                l=mid+1;
            cond=false;
        }
        return l;
    }
};
