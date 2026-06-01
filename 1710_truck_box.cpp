class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int S) {
        priority_queue<pair<int, int>> heap;
        int ans=0;
        for(const auto& x: box)
            heap.push({x[1], x[0]});
        while(S!=0 && !heap.empty())
        {
            int s=heap.top().second, u=heap.top().first;
            if(s>S)
                s=S;
            ans+=s*u;
            heap.pop();
            S-=s;
        }
        return ans;
    }
};
