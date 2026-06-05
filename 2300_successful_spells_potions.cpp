class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        // unordered_map<int, int> hash;
        int m=potions.size(), n=spells.size();
        // hash.reserve(n);
        // hash.max_load_factor(0.25);
        vector<int> ans(n, 0);
        sort(potions.begin(), potions.end());
        for(int j=0;j<n; j++)
        {
            long long s=spells[j];
            int l=0, r=m;
            // if(hash.contains(s)) 
            // {
            //     ans[j]=hash[s];
            //     continue;
            // }
            while(l<r)
            {
                int mid=l+(r-l)/2;
                long long p= potions[mid]*s;
                if(p<success)
                    l=mid+1;
                else
                    r=mid;                           
            }
            // hash[s]=m-i;
            ans[j]=m-r;
        }
        return ans;
    }
};
