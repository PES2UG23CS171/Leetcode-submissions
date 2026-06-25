/* 
//for n<30
class Solution {
public:
    void back(int n, vector<int>& curr, int l, int r, bool z, int& ans) {
        if(curr.size()==n) {
            ans++;
            return;
        }
        if(z) {
            for(int i=curr.back()+1; i<=r; i++) {
                curr.push_back(i);
                back(n, curr, l, r, !z, ans);
                curr.pop_back();
            }
        }
        else {
            for(int i=curr.back()-1; i>=l; i--) {
                curr.push_back(i);
                back(n, curr, l, r, !z, ans);
                curr.pop_back();
            }
        }
    }
    int zigZagArrays(int n, int l, int r) {
        int ans=0;
        for(int i=l; i<=r; i++) {
            vector<int> curr;
            curr.reserve(n);
            curr.push_back(i);
            back(n, curr, l, r, true, ans);
            back(n, curr, l, r, false, ans);
        }
        return ans;
    }
};

// optimized with memoization 
class Solution {
public:
    int dp(vector<vector<vector<int>>>& mem, int l, int r, int n, int z, int x, int p) {
        if(p==n) 
            return 1;
        if(mem[p][x-l][z] != -1)
            return mem[p][x-l][z];
        int res=0;
        if(z) {
            for(int i=x+1; i<=r; i++) 
                res+=dp(mem, l, r, n, 0, i, p+1);
        }
        else {
            for(int i=x-1; i>=l; i--)
                res+=dp(mem, l, r, n, 1, i, p+1);
        }
        mem[p][x-l][z]=res;
        return res;
    }
    int zigZagArrays(int n, int l, int r) {
        vector<vector<vector<int>>> mem(n, vector<vector<int>> (r-l+1, vector<int> (2, -1)));
        int ans=0;
        for(int i=l; i<=r; i++) {
            ans+=dp(mem, l, r, n, 0, i, 1);
            ans+=dp(mem, l, r, n, 1, i, 1);
        }
        return ans;
    }
};
*/
