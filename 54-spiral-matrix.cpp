class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l=0, r=matrix[0].size(), t=0, b= matrix.size(), sol=r*b;
        r--;
        b--;
        vector<int> ans;
        ans.reserve(sol);
        while(ans.size()<sol) {
            for(int i=l; i<=r; i++)
                ans.push_back(matrix[t][i]);
            t++;
            if(ans.size()==sol) break;
            for(int i=t; i<=b; i++)
                ans.push_back(matrix[i][r]);
            r--;
            if(ans.size()==sol) break;
            for(int i=r; i>=l; i--)
                ans.push_back(matrix[b][i]);
            b--;
            if(ans.size()==sol) break;
            for(int i=b; i>=t; i--)
                ans.push_back(matrix[i][l]);
            l++;
        }
        return ans;
    }
};
