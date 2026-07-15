class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s=cost.size(), ans=0, sum=0, rs=0;
        for(int i=0; i<s; i++) {
            int v=gas[i]-cost[i];
            sum+=v;
            rs+=v;
            if(rs<0) {
                ans=(i+1)%s;
                rs=0;
            }
        }
        if(sum<0)
            return -1;
        return ans;
    }
};
