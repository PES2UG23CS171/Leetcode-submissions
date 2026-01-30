class Solution {
public:
    int totalNQueens(int n) 
    {
        vector<vector<int>> dead(n, vector<int>(n,0));
        int ans=0;
        back(ans, dead, n, 0);
        return ans;
    }
    void back(int& ans, vector<vector<int>>& dead, int n, int l)
    {
        if(l==n)
        {
            ans++;
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(!dead[l][i]==0)
                continue;

            for(int j=l; j<n; j++)
                dead[j][i]++;
            int t=l+1;
            for(int j=i+1; j<n && t<n; j++)
                dead[t++][j]++;
            t=l+1;
            for(int j=i-1; j>=0 && t<n; j--)
                dead[t++][j]++;

            back(ans, dead, n, l+1);

            for(int j=l; j<n; j++)
                dead[j][i]--;
            t=l+1;
            for(int j=i+1; j<n && t<n; j++)
                dead[t++][j]--;
            t=l+1;
            for(int j=i-1; j>=0 && t<n; j--)
                dead[t++][j]--;
        }
    }
};
