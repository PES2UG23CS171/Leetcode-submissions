class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> mem(n, 1);
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                mem[j]+=mem[j-1];
            }
        }
        return mem.back();
    }
};
