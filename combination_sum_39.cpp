class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        back(nums, t, ans, curr, 0);
        return ans;
    }
    void back(vector<int>& nums, int t, vector<vector<int>>& ans, vector<int>& curr, int j)
    {
        if(t==0)
        {
            ans.push_back(curr);
            return;
        }
        for(int i=j; i<nums.size(); i++)
        {
            if(t-nums[i]<0)
                return;
            curr.push_back(nums[i]);
            back(nums, t-nums[i], ans, curr, i);
            curr.pop_back();
        }
    }
};
