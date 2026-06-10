class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) 
    {
        int l=1, r=*max_element(nums.begin(), nums.end());
        while(l<r)
        {
            int mid=l+(r-l)/2, div=0;
            for(int i:nums)
                div+=(i+mid-1)/mid;
            if(div<=t)
                r=mid;
            else 
                l=mid+1;
        }
        return l;
    }
};
