class Solution {
public:
    int maximizeSweetness(vector<int>& S, int k) {
        int l=S[0], r=1;
        for(int i: S)
        {
            l=min(l, i);
            r+=i;
        }
        k++;
        while(l<r)
        {
            int mid=l+(r-l)/2, c=0;
            long v=0;
            for(int i=0; i<S.size(); i++)
            {
                v+=S[i];
                if(v>=mid)
                {
                    c++;
                    v=0;
                }
            }
            if(c>=k)
                l=mid+1;
            else 
                r=mid;
        }
        return l-1;
    }
};
