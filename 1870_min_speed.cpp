class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double h) 
    {
        if(h<=(int)dist.size()-1) return -1;
        int l=1, r=INT_MAX/2;       
        while(l<r)
        {
            int mid=l+(r-l)/2;
            double avg=0;   
            for(int i=0; i<dist.size()-1; i++)
                avg+=(dist[i]+mid-1)/mid;
            avg+=(double)dist.back()/mid;
            if(avg<=h)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
