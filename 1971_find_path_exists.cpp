//RECURSIVE METHOD
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) 
    {
        vector<vector<int>> graph(n);
        for(const auto& e: edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> seen(n, false);
        stack<int> curr;
        curr.push(s);
        while(!curr.empty())
        {
            s= curr.top();
            curr.pop();
            if(s==d) return true;
            for(int i: graph[s])
            {
                if(!seen[i])
                {
                    seen[i]=true;
                    curr.push(i);
                }
            }
        }
        return false;
    }
};
/*
//Backtracking- slow because recursion and chances of stack overflow

class Solution {

public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d)

    {

        vector<vector<int>> graph(n);

        for (const auto& e : edges)

        {

            graph[e[0]].push_back(e[1]);

            graph[e[1]].push_back(e[0]);
        }

        vector<bool> seen(n, false);

        bool f = false;

        return dfs(graph, seen, f, s, d, n);
    }

    bool dfs(vector<vector<int>>& graph, vector<bool>& seen, bool& f, int s,
             int d, int n)

    {

        seen[s] = true;

        if (f || s == d)

        {

            f = true;

            return f;
        }

        for (int i : graph[s])

        {

            if (f)
                return f;

            if (!seen[i])

                dfs(graph, seen, f, i, d, n);
        }

        return f;
    }
};

*/
