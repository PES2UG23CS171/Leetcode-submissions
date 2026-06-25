class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& OG) {
        vector<int> mem(OG[0].size(), 0);
        for(int i=0; i<OG[0].size(); i++) {
            if(OG[0][i])    break;
            mem[i]=1;
        }
        for(int i=1; i<OG.size(); i++) {
            if(OG[i][0])    mem[0]=0;
            for(int j=1; j<OG[0].size(); j++) {
                if(OG[i][j]) {
                    mem[j]=0;
                    continue;
                }
                mem[j]+=mem[j-1];
            }
        }
        return mem.back();
    }
};
