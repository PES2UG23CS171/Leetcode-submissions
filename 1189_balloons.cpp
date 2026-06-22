class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        vector<int> B(5, 0);
        for(char c: text)
        {
            switch(c)
            {
                case 'b':
                    B[0]++;
                    break;
                case 'a':
                    B[1]++;
                    break;
                case 'l':
                    B[2]++;
                    break;
                case 'o':
                    B[3]++;
                    break;
                case 'n':
                    B[4]++;
                    break;
            }
        }
        B[2]/=2;
        B[3]/=2;
        return *min_element(B.begin(), B.end());
    }
};
