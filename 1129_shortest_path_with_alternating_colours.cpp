class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) 
    {
        vector<vector<vector<int>>> hash(n, vector<vector<int>> (2));
        for(const auto& x: red)
            hash[x[0]][1].push_back(x[1]);
        for(const auto& x: blue)
            hash[x[0]][0].push_back(x[1]);
        //red=1 true  blue=0 false
        vector<int> ans(n, INT_MAX);
        vector<vector<bool>> seen(n, vector<bool>(2, false));
        seen[0][0]=true;
        seen[0][1]=true;
        ans[0]=0;
        queue<pair<int, bool>> next;
        next.push({0, true});
        next.push({0, false});
        int step=0;
        while(!next.empty())
        {
            int qsize=next.size();
            step++;
            while(qsize--)
            {
                const auto& x=next.front();
                int node=get<0>(x), col=(get<1>(x))? 0: 1;
                for(int i: hash[node][col])
                {
                    if(!seen[i][col])
                    {
                        next.push({i, !get<1>(x)});
                        ans[i]=min(ans[i], step);
                        seen[i][col]=true;
                    }
                }
                next.pop();
            }
        }
        for(int i=0; i<n; i++)
            if(ans[i]==INT_MAX)  ans[i]=-1;
        return ans;
    }
};
