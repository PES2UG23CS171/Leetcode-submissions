class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<int> in(n, 0);
        vector<unordered_set<int>> ed(n);
        int ans=0;
        for(auto x: nums) {
            in[x[0]]++;
            ed[x[1]].insert(x[0]);
        }
        queue<int> next;
        for(int i=0; i<n; i++) {
            if(in[i]==0)    next.push(i);
        }
        while(!next.empty()) {
            int curr=next.front();
            ans++;
            next.pop();
            for(int i: ed[curr]) {
                in[i]--;
                if(in[i]==0)
                    next.push(i);
            }
        }
        return (ans==n)? true: false;
    }
};
