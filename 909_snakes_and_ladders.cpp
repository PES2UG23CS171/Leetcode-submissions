class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& bd) 
    {
        int step=0, n=bd.size(), m=bd[0].size(), l=m*n, c=1;
        bool d=true;
        vector<int> jump(l+1, -1);
        vector<bool> seen(l+1, false);
        for(int i=n-1; i>=0; i--)
        {
            if(!d)
                for(int j=m-1; j>=0; j--)
                {
                    if(bd[i][j] != -1)
                        jump[c]= bd[i][j];
                    c++;
                }
            else
                for(int j=0; j<m; j++)
                {
                    if(bd[i][j] != -1)
                        jump[c]= bd[i][j];
                    c++;
                }
            d=!d;
        }
        queue<int> next;
        next.push(1);
        seen[1]=true;
        while(next.size())
        {
            step++;
            int qsize=next.size();
            while(qsize--)
            {
                int f=next.front();
                next.pop();
                for(int i=1; i<=6 && i+f<=l; i++)
                {
                   int d=(jump[i+f]==-1)? i+f: jump[i+f];
                   if(d==l) return step;
                   if(!seen[d])
                   {
                        seen[d]=true;
                        next.push(d);
                   }
                }
            }
        }
        return -1;
    }
};
