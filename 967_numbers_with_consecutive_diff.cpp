class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        vector<int> ans;
        for(int i=1; i<10; i++)
            back(n, k, ans, i, 1);
        return ans;        
    }
    void back(int n, int k, vector<int>& ans, int curr, int c)
    {
        if(c==n)
        {
            ans.push_back(curr);
            return;
        }
        int d=curr % 10;
        for(int i=0; i<10; i++)
        {
            if(c>=n)
                return;
            int s=abs(i-d);
            if( s==k && s>=0)
                back(n, k, ans, curr*10+i, c+1);
        }
    }
};
