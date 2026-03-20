class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& x) 
    {
        int dir[4][2]={{0,1}, {0,-1}, {1, 0}, {-1, 0}};
        int n=maze.size(), m=maze[0].size(), s=0;
        queue<int> next;
        next.push(x[0]*m+x[1]);
        maze[x[0]][x[1]]='+';
        while(next.size())
        {
            s++;
            int qsize=next.size();
            while(qsize--)
            {
                int f=next.front(), r=f/m, c=f%m;
                next.pop();
                for(auto [i, j]: dir)
                {
                    int x=r+i, y=c+j;
                    if(x>=0 && x<n && y>=0 && y<m && maze[x][y]=='.')
                    {
                        maze[x][y]='+';
                        if(x==0 || x==n-1 || y==0 || y==m-1)
                            return s;
                        next.push(x*m+y);
                    }
                }
            }
        }
        return -1;
    }
};
