class Solution {
public:
    int numRescueBoats(vector<int>& people, int l) 
    {
        sort(people.begin(), people.end());
        int ans=0, j=0;
        for(int i=people.size()-1; i>=j; i--)
        {
            if(people[j]+people[i]<=l)
            {
                ans++;
                j++;
            }
            else
                ans++;
        }
        return ans;
    }
};
