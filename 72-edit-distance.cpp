class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1=word1.size()+1, w2=word2.size()+1;
        if(w1>w2) {
            swap(word1, word2);
            swap(w1, w2);
        }
        vector<vector<int>> mem(w1, vector<int> (w2, 0));
        for(int i=0; i<w1; i++)
            mem[i][0]=i;
        for(int i=0; i<w2; i++)
            mem[0][i]=i;
        for(int i=1; i<w1; i++) {
            for(int j=1; j<w2; j++) {
                if(word1[i-1]==word2[j-1])
                    mem[i][j]=mem[i-1][j-1];
                else
                    mem[i][j]=min({mem[i-1][j], mem[i][j-1], mem[i-1][j-1]})+1;
            }
        }
        return mem[w1-1][w2-1];
    }
};
