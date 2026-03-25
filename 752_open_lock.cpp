class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        if(target=="0000") return 0;
        unordered_set<int> dead;
        for(auto S: deadends)
            dead.insert(stoi(S));
        if(dead.contains(0)) return -1;
        dead.insert(0);
        queue<int> next;
        next.push(0);
        int ans=0, T=stoi(target);
        auto make= [&](int x1, int x2, int x3, int x4)-> int{
            return x1*1000+ x2*100+ x3*10+ x4;
        };
        auto inc= [&](int x)->int{
            return (x+1)%10;
        };
        auto dec=[&](int x)->int{
            return (x-1+10)%10;
        };
        while(next.size())
        {
            ans++;
            int qsize=next.size();
            while(qsize--)
            {
                int f=next.front(), d[4], put[8];
                next.pop();
                for(int i=0; i< 4; i++)
                {
                    d[i]=f%10;
                    f/=10;
                }
                put[0]=make(inc(d[3]), d[2], d[1], d[0]);
                put[1]=make(d[3], inc(d[2]), d[1], d[0]);
                put[2]=make(d[3], d[2], inc(d[1]), d[0]);
                put[3]=make(d[3], d[2], d[1], inc(d[0]));
                put[4]=make(dec(d[3]), d[2], d[1], d[0]);
                put[5]=make(d[3], dec(d[2]), d[1], d[0]);
                put[6]=make(d[3], d[2], dec(d[1]), d[0]);
                put[7]=make(d[3], d[2], d[1], dec(d[0]));
                for(int x: put)
                {
                    if(x==T) return ans;
                    if(!dead.contains(x))
                    {
                        next.push(x);
                        dead.insert(x);
                    }
                }
            }
        }
        return -1;
    }
};
