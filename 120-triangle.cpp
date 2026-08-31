class Solution {
public:
    int dp(vector<vector<int>>& nums, vector<vector<int>>& mem, int r, int c) {
        if(mem[r][c]!=INT_MAX)
            return mem[r][c];
        int n=nums.size(); 
        if(r==n-1)
            return mem[r][c]=nums[r][c];
        int ans=dp(nums, mem, r+1, c);
        if(c+1<nums[r+1].size())
            ans=min(ans, dp(nums, mem, r+1, c+1));
        return mem[r][c]=ans+nums[r][c];
    }
    int minimumTotal(vector<vector<int>>& nums) {
        int n=nums.size(), m= nums[n-1].size();
        vector<vector<int>> mem(n, vector<int> (m, INT_MAX));
        return dp(nums, mem, 0, 0);
    }
};
