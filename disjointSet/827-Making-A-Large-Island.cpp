#define ii pair<int,int> 
class DisjointSet {
    public:
        int static const N = 505;
        int size[N][N];
        ii par[N][N];

    DisjointSet(int n) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                par[i][j] = {i,j};
                size[i][j] = 1;
            }
        }
    }
    ii find(ii p) {
        if (par[p.first][p.second] == p) return p;
        return par[p.first][p.second] = find(par[p.first][p.second]);
    }
    void unite(ii i, ii j) {
        ii pari = find(i);
        ii parj = find(j);

        if (pari == parj) return;

        if (size[pari.first][pari.second] < size[parj.first][parj.second]) {
            par[pari.first][pari.second] = parj;
            size[parj.first][parj.second] += size[pari.first][pari.second];
            size[pari.first][pari.second]  = 0;
        } else {
            par[parj.first][parj.second]  = pari;
            size[pari.first][pari.second]  +=  size[parj.first][parj.second] ;
            size[parj.first][parj.second]  = 0; 
        }
    
    }
};

class Solution {
public:
    int n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};    
    bool valid(int i, int j) {
        return i < n && j < n && i >= 0 && j >= 0;
    }
    
    int largestIsland(vector<vector<int>>& v) {
        n = v.size();

        DisjointSet island = DisjointSet(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (!v[i][j]) continue;
                for (int l = 0 ; l < 4 ; l++) {
                    int x = i + dir[l][0];
                    int y = j + dir[l][1];
                    if (valid(x, y) && v[x][y]) island.unite({i, j}, {x, y});
                 
                }
            }
        }
        
        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                set<ii> cur;
                if (v[i][j]) {
                    ii par = island.find({i,j});
                    mx = max(mx, island.size[par.first][par.second]);
                    continue;
                };
                for(int l = 0; l < 4; l++) {
                    int x = i + dir[l][0];
                    int y = j + dir[l][1];
                    if (valid(x, y) && v[x][y]) {
                        ii par = island.find({x, y});
                        cur.insert(par);
                    }
                }
                int curMx = 1;
                for(auto x : cur) {
                    curMx += island.size[x.first][x.second];
                }
                mx = max(mx, curMx);
            }
        }
        return mx;
    }
};