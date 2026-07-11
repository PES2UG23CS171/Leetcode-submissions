class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        while(n!=1) {
            int m=n;
            n=0;
            while(m) {
                int d=m%10;
                d*=d;
                n+=d;
                m/=10;
            }
            if(hash.contains(n))    return false;
            hash.insert(n);
        }
        return true;
    }
};
