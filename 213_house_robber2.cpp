class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1)  return nums[0];
        int n=nums.size();
        return max(dp(nums, 0, n-1), dp(nums, 1, n));
    }
    int dp(vector<int>& nums, int s, int e)
    {
        int p1=0, p2=0;
        for(int i=s; i<e; i++)
        {
            int curr=max(p1, p2+nums[i]);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
};
