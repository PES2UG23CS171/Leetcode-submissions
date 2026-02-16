class Solution {
public:
    int searchInsert(vector<int>& nums, int t) 
    {
        int l=0, r=nums.size();
        while(l<r)
        {
            int m= l + (r-l)/2;
            if(t < nums[m])
                r=m;
            else
            {
                l=m+1;
                if(nums[m]==t)
                    return m;
            }
        }
        return l;
    }
};
