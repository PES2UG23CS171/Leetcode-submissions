class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> graph(n);
        for(const auto& e: edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int ans=0;
        vector<bool> seen(n, false);
        for(int i=0; i<n; i++)
        {
            if(!seen[i])
            {
                seen[i]=true;
                dfs(graph, seen, i);
                ans++;
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& graph, vector<bool>& seen, int n)
    {
        stack<int> curr;
        curr.push(n);
        while(!curr.empty())
        {
            int i=curr.top();
            curr.pop();
            for(int x: graph[i])
            {
                if(!seen[x])
                {
                    curr.push(x);
                    seen[x]=true;
                }
            }
        }
    }
};
