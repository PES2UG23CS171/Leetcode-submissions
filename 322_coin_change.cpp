class Solution {
public:
    int coinChange(vector<int>& coins, int amt) 
    {
        vector<int> mem(amt+1, INT_MAX);
        mem[0]=0;
        for(int i=0; i< amt+1; i++)
        {
            for(int c: coins)
            {
                if(i-c>=0 && mem[i-c] != INT_MAX)
                    mem[i]= min(mem[i], mem[i-c]+1);
            }
        }
        return (mem[amt]==INT_MAX)? -1: mem[amt]; 
    }
};
