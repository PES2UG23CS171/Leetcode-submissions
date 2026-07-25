class Solution {
public:
    int maxProduct(int n) {
        int mx[3]={0,0, 0};
        while(n) {
            int i=2;
            mx[2]=n%10;
            while(i>0 && mx[i]>=mx[i-1]) {
                swap(mx[i], mx[i-1]);
                i--;
            }
            n/=10;
        }
        return mx[0]*mx[1];
    }
};
