class Solution {
public:
    bool canReach(vector<int>& arr, int s) 
    {
        int S=arr.size();
        vector<bool> seen(S, false);
        queue<int> next;
        next.push(s);
        seen[s]=true;
        while(!next.empty())
        {
            int curr=next.front(), v=arr[curr];
            next.pop();
            if(v==0)    return true;
            int a=curr+v, b=curr-v;
            if(a<S && !seen[a])    
            {
                next.push(a);
                seen[a]=true;
            }
            if(b>=0 && !seen[b])   
            {
                seen[b]=true;
                next.push(b);
            }
        }
        return false;
    }
};
