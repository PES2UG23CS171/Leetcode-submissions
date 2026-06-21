class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int s=*max_element(costs.begin(), costs.end());
        vector<int>arr (s+1, 0);
        for(int i: costs)
            arr[i]++;
        s=0;
        for(int i=0; i<arr.size(); i++)
        {
            while(arr[i]>0 && coins-i>=0)
            {
                coins-=i;
                arr[i]--;
                s++;
            }
        }
        return s;
    }
};
