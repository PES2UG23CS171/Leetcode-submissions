class Solution {
public:
    string intToRoman(int num) {
        string R="IVXLCDMJK", ans="";
        ans.reserve(10);
        for(int i=0; num; i+=2) {
            int d= num%10;
            num/=10;
            switch(d) {
                case 1:
                case 2:
                case 3:
                    ans.append(d, R[i]);
                    break;
                case 4:
                    ans.push_back(R[i+1]);
                    ans.push_back(R[i]);                    
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                    d-=5;
                    ans.append(d, R[i]);
                    ans.push_back(R[i+1]);
                    break;
                case 9:
                    ans.push_back(R[i+2]);            
                    ans.push_back(R[i]);            
            }    
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
