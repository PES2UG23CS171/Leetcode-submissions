class Solution {
public:
    bool checker(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& mem) {
        if(mem[i][j]!=-1)
            return mem[i][j]==1;
        int n1=s1.size(), n2=s2.size(), n3=s3.size(), k=i+j;
        bool ans=(k==n3)?true: false;
        if(i<n1 && j<n2 && s3[k]==s1[i] && s3[k]==s2[j])
            ans=checker(s1, s2, s3, i+1, j, mem) || checker(s1, s2, s3, i, j+1, mem);
        else if(i<n1 && s3[k]==s1[i])
            ans=checker(s1, s2, s3, i+1, j, mem);
        else if(j<n2 && s3[k]==s2[j])
            ans=checker(s1, s2, s3, i, j+1, mem);
        mem[i][j]=(ans)? 1: 0;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), n3=s3.size();
        vector<vector<int>> mem(n1+1, vector<int> (n2+1, -1));
        if(n3!=n1+n2)
            return false;
        return checker(s1, s2, s3, 0, 0, mem);
    }
};
