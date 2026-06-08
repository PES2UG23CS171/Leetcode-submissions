class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& Q) 
    {
        int m=Q.size(), n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++)
            nums[i]+=nums[i-1];        
        vector<int> ans(m, 0);
        for(int i=0; i<m; i++)
        {
            int s=Q[i], l=0, r=n;
            while(l<r)
            {
                int mid=l+(r-l)/2;
                if(s<nums[mid])
                    r=mid;
                else
                    l=mid+1;                   
            }
            ans[i]=r;
        }
        return ans;
    }
};
