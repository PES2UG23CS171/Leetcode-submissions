class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> heap;
        for(const auto& a: points)
        {
            int x=a[0], y=a[1];
            double d=sqrt(x*x + y*y);
            heap.push({d, x, y});
        }
        vector<vector<int>> ans;
        for(int i=0; i<k; i++)
        {
            int x=get<1>(heap.top());
            int y=get<2>(heap.top());
            heap.pop();
            ans.push_back({x,y});
        }
        return ans;
    }
};
