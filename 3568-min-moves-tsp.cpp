class Solution {
public:
    int minMoves(vector<string>& C, int G) {
        int tot=0, n=C.size(), m=C[0].size(), ans=0, start;
        unordered_map<int, int> hash;
        queue<tuple<int, int, int>> next;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                char c= C[i][j];
                if(c=='L') {
                    tot++;
                    hash[i*m+j]=tot;
                }
                else if(c=='S') {
                    start=i*m+j;
                }
            }
        }
        if(tot==0)
            return 0;
        tot=1<<(1+tot);
        int dir[4][2]={{0,1}, {0,-1}, {1, 0}, {-1, 0}};
        vector<vector<vector<int>>> seen(n, vector<vector<int>> (m, vector<int> (tot, -1)));
        next.push({start, G, 0});
        seen[start/m][start%m][0]=G;
        while(!next.empty()) {
            int qsize=next.size();
            ans++;
            while(qsize--) {
                auto [p, e, l]= next.front();
                next.pop();
                int r=p/m, c=p%m;
                for(int i=0; i<4; i++) {
                    int nr=r+dir[i][0], nc=c+dir[i][1], np=nr*m+nc, ne=e-1, nl=l;
                    if(nr<0 || nr>=n || nc<0 || nc>=m || C[nr][nc]=='X')
                        continue;
                    
                    if(C[nr][nc]=='L' && !(l & 1<<hash[np])) {
                        nl=l|1<<hash[np];
                        if(nl==tot-2)
                            return ans;
                    }
                    else if(C[nr][nc]=='R')
                        ne=G;
                    
                    if(ne>0 && ne>seen[nr][nc][nl]) {
                        seen[nr][nc][nl]=ne;
                        next.push({np, ne, nl});
                    }
                }
            }
        }
        return -1;
    }
};
