class Solution {
public:
    int small(int a, int b, int c)
    {
        if(a<=b && a<=c) return a;
        else if(b<=a && b<=c) return b;
        return c;
    }
    int great(int a, int b, int c)
    {
        if(a>=b && a>=c) return a;
        else if(b>=a && b>=c) return b;
        return c;
    }
    int maxProduct(vector<int>& nums) {
        int ans=*max_element(nums.begin(), nums.end());
        int min= nums[0], max= nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                min=1;
                max=1;
                continue;
            }
            int b= min*nums[i], c= max*nums[i];
            min= small(nums[i], b, c);
            max=great(nums[i], b, c);
            ans=great(ans, min, max);
        }
        return ans;
    }
};
