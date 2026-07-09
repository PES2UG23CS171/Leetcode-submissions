class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int D, vector<vector<int>>& Q) {
        vector<bool> ans(Q.size(), false);
        vector<int> path(n, 0);
        int s=0;
        for(int i=1; i<n; i++) {
            if(nums[i]-nums[i-1]>D) {
                for(int j=s; j<i; j++)
                    path[j]=i-1;
                s=i; 
            }
        }
        if(s<n) {
            for(int i=s; i<n; i++) 
                path[i]=n-1;
        }
        for(int i=0; i<Q.size(); i++) {
            int s=min(Q[i][0], Q[i][1]), d=max(Q[i][0], Q[i][1]);
            if(path[s]>=d)
                ans[i]=true;
        }
        return ans;
    }
};
