class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        string curr="";
        vector<string> ans;
        back(ans, curr, n*2, 0, 0);
        return ans;
    }
    void back(vector<string>& ans, string& curr, int N, int l, int r)
    {
        if(curr.size()==N && r==l)
        {
            ans.push_back(curr);
            return;
        }
        if(curr.size()>=N)
            return;
        if(l>r)
        {
            curr.push_back(')');
            r++;
            back(ans, curr, N, l, r);
            r--;
            curr.pop_back();
        }
        if(l<N/2)
        {
            l++;
            curr.push_back('(');
            back(ans, curr, N, l, r);
            l--;
            curr.pop_back();
        }
    }
};
