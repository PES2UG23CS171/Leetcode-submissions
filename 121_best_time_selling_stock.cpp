class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, p=prices[0];
        for(int i=1; i<prices.size(); i++) {
            ans=max(ans, prices[i]-p);
            p=min(p, prices[i]);
        }
        return ans;
    }
};
