class Solution {
public:
    int candy(vector<int>& R) {
        int ans=0, ss=R.size();
        vector<int> left(ss, 1), right(ss, 1);
        for(int i=ss-1; i>0; i--)
        {
            if(R[i]<R[i-1])
                right[i-1]=right[i]+1;
            // else if(R[i]==R[i-1])
            //     right[i-1]=right[i];
        }
        for(int i=1; i<ss; i++)
        {
            if(R[i]>R[i-1])
                left[i]=left[i-1]+1;
            // else if(R[i]==R[i-1])
            //     left[i]=left[i-1];
        }
        for(int i=0; i<ss; i++)
            ans+=max(left[i], right[i]);
        return ans;
    }
};
