class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        int p=0, sum=0;
        while(n) {
            int d=n%10;
            sum+=d;
            n/=10;
            ans+= pow(10, p)*d;
            if(d!=0)    p++;
        }
        ans*=sum;
        return ans;
    }
};
