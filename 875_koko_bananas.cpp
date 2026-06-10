class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l=1, r=*max_element(piles.begin(), piles.end());
        while(l<r)
        {
            int m=l+(r-l)/2, avg=0;
            for(int i: piles)
            {
                // if(i<=m)
                //     avg++;
                // else 
                // This handles that smaller case also
                    avg+= (i+m-1)/m;
            }
            if(h<avg)
                l=m+1;
            else
                r=m;
        }
        return l;
    }
};
