class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int l=*min_element(nums.begin(), nums.end()), r=*max_element(nums.begin(), nums.end()), n=nums.size();
        if(l==r)
            return 0;
        long long ans=LONG_LONG_MAX;
        auto calc= [=](int t)->long long {
            long long val=0;
            for(int i=0; i<n; i++)
                val+=(long long)abs(t-nums[i])*cost[i];
            return val;
        };
        while(l<r) {
            int mid= l+(r-l)/2;
            long long val=calc(mid), left=calc(mid-1), right=calc(mid+1);
            ans=min({ans, val, left, right});
            if(left<right)
                r=mid;
            else
                l=mid+1;
        }
        return ans;
    }
};
