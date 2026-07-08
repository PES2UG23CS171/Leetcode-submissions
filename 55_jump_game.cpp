class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx=nums[0];
        for(int i=0; i<nums.size() && i<=mx; i++) {
            mx=max(mx, i+nums[i]);
            if(mx>=nums.size()-1)
                return true;
        }
        return false;
    }
};
/*
//complex BFS solution 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        queue<int> next;
        next.push(0);
        int n=nums.size();
        vector<bool> seen(n, false);
        seen[0]=true;
        while(!next.empty()) {
            int curr=next.front();
            next.pop();
            if(curr>=n-1 || curr+nums[curr]>=n-1)  return true;
            for(int i=1; i<=nums[curr]; i++) {
                int v=curr+i;
                if(v<n && !seen[v]) {
                    next.push(v);
                    seen[v]=true;
                }
            }
        }
        return false;
    }
};

*/
