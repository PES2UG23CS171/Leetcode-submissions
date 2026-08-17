class Solution {
public:
    long long bracket(string& S, int& i, int& n) {
        long long ans=0;
        bool neg=false;
        auto pusher= [&](long long e) {
            if(neg)
                ans-=e;
            else
                ans+=e;
        };
        while(i<n && S[i]!=')') {
            if(S[i]=='(') {
                pusher(bracket(S, ++i, n));
            }
            else if(S[i]=='-') {
                neg=true;
            }
            else if(S[i]=='+') {
                neg=false;
            }
            else if(isdigit(S[i])) {
                string d;
                while(i<n && isdigit(S[i])) {
                    d.push_back(S[i++]);
                }
                pusher(stoll(d));
                continue;
            }
            i++;
        }
        return ans;
    }
    int calculate(string s) {
        int n=s.size(), i=0;
        return (int)bracket(s, i, n);
    }
};
