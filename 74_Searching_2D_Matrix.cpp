class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int t) 
    {
        int u= nums.size(), d=0, r=nums[0].size(), l=0;
        while(d<u)
        {
            int m= d + (u-d)/2;
            if(nums[m][r-1] > t)
                u=m;
            else
            {
                if(nums[m][r-1] == t) return true;
                d=m+1;
            }
        }
        if(u>=nums.size()) u=nums.size()-1;
        while(l<r)
        {
            int m= l + (r-l)/2;
            if(t < nums[u][m])
                r=m;
            else
            {
                if(nums[u][m] == t) return true;
                l=m+1;
            }
        }
        return false;
    }
};
