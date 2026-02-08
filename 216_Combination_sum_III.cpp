class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        back(ans, curr, k, n);
        return ans;
    }
    void back(vector<vector<int>>& ans, vector<int>& curr, int k, int n)
    {
        if(curr.size()==k && n==0)
        {
            ans.push_back(curr);
            return;
        }
        int i=(curr.empty())? 1: curr.back()+1;
        for( ; i<10 && curr.size() < k && n-i> -1; i++)
        {
            curr.push_back(i);
            back(ans, curr, k, n-i);
            curr.pop_back();
        }
    }
};
