class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> mem(cost.size(), -1);
        return min(dp(mem, cost, 0), dp(mem, cost, 1));
    }
    int dp(vector<int>& mem, vector<int>& cost, int i)
    {
        if(i>=cost.size())
            return 0;
        if(mem[i]==-1)
            mem[i]=min(cost[i] + dp(mem, cost, i+1), cost[i] + dp(mem, cost, i+2));
        return mem[i];
    }
};
