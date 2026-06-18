class Solution {
public:
    int trap(vector<int>& H) 
    {
        int l=0, ans=0, r=0, S=H.size();
        vector<int> right(S, 0), left(S, 0);
        for(; r<S; r++)
        {
            if(H[r]>=H[l])
            {
                int j=l+1;
                while(j<r)
                    left[j++]=max(0, H[l]-H[j]);
                l=r;
            }
        }
        r=S-1;
        for(l=S-1; l>=0; l--)
        {
            if(H[l]>=H[r])
            {
                int j=r-1;
                while(j>l)
                    right[j--]=max(0, H[r]-H[j]);
                r=l;
            }
        }
        for(l=0; l<S; l++)
            ans+=max(left[l], right[l]);
        return ans;
    }   
};
