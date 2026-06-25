class Solution {
public:
    int minDistance(string w1, string w2) {
        vector<int> prev(w1.size()+1, 0), curr(w1.size()+1, 0);
        for(int i=0; i<=w1.size(); i++)
            prev[i]=i;
        for(int i=0; i<w2.size(); i++) {
            curr[0]=i+1;
            for(int j=0; j<w1.size(); j++) {
                if(w1[j]==w2[i])
                    curr[j+1]=prev[j];
                else
                    curr[j+1]=min(prev[j+1], curr[j])+1;
            }
            swap(curr, prev);
        }
        return prev.back();
    }
};
