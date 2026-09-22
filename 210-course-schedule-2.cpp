class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> hash;
        hash.reserve(n);
        vector<int> num(n, 0);
        for(const auto& x: pre) {
            hash[x[1]].push_back(x[0]);
            num[x[0]]++;
        }
        queue<int> next;
        vector<bool> seen(n, false);
        for(int i=0; i<n; i++) {
            if(num[i]==0) {
                next.push(i);
            }
        }
        if(next.empty())
            return {};
        vector<int> ans;
        while(!next.empty()) {
            int curr=next.front();
            next.pop();
            seen[curr]=true;
            ans.push_back(curr);
            for(int i: hash[curr]) {
                if(seen[i])
                    continue;
                num[i]--;
                if(num[i]==0)
                    next.push(i);
            }
        }
        if(ans.size()!=n)
            return {};
        return ans;
    }
};
