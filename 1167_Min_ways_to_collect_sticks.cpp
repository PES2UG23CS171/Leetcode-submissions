class Solution {
public:
    int connectSticks(vector<int>& sticks) 
    {
        priority_queue<int, vector<int>, greater<int>> minH(sticks.begin(), sticks.end());
        int ans=0;
        while(minH.size() != 1)
        {
            int a=minH.top();
            minH.pop();
            a+=minH.top();
            minH.pop();
            minH.push(a);
            ans+=a;
        }
        return ans;
    }
};
