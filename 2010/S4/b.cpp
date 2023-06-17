//
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9

const int MAXN = 1e3 + 10;
int m, e[MAXN], c[MAXN][10], p[MAXN][10];
ll dij[MAXN], wall[MAXN][MAXN], price[MAXN][MAXN], par[MAXN];
vector <int> v[MAXN], cor[MAXN][MAXN];
bool mark[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> e[i];
        for (int j = 0; j < e[i]; j ++) {
            cin >> c[i][j];
        }
        for (int j = 0; j < e[i]; j ++) {
            cin >> p[i][j];
        }
        fill(wall[i], wall[i] + m + 1, -1);
    }
    for (int i = 1; i <= m; i ++) { // get price for each edge
        cor[c[i][0]][c[i][e[i] - 1]].pb(i); 
        cor[c[i][e[i] - 1]][c[i][0]].pb(i); 
        price[c[i][0]][c[i][e[i] - 1]] = price[c[i][e[i] - 1]][c[i][0]] = p[i][e[i] - 1];
        for (int j = 1; j < e[i] ; j ++) {
            cor[c[i][j]][c[i][j - 1]].pb(i); 
            cor[c[i][j - 1]][c[i][j]].pb(i);
            price[c[i][j]][c[i][j - 1]] = price[c[i][j - 1]][c[i][j]] = p[i][j - 1];
        }
    }
    // for (int i = 1; i <= 1e3; i ++) {
    //     for (int j = i + 1; j <= 1e3; j ++) {
    //         if (cor[i][j].empty()) continue;
    //         cout << i << " " << j << ": " << price[i][j] << ": " << cor[i][j][0] << " ";
    //         if (cor[i][j].size() == 2)
    //             cout << cor[i][j][1];
    //         else
    //             cout << 0;
    //         cout << '\n';
    //     }
    // }
    for (int i = 1; i <= 1e3; i ++) { // get price of pen to pen
        for (int j = i + 1; j <= 1e3; j ++) {
            if (cor[i][j].size() == 1) {
                wall[cor[i][j][0]][0] = wall[0][cor[i][j][0]] = price[i][j];
                // cout << "edge " << i << " " << j << " connects " << cor[i][j][0] << " and 00 with " << price[i][j] << '\n';
            }
            else if (cor[i][j].size() == 2) {
                wall[cor[i][j][0]][cor[i][j][1]] = wall[cor[i][j][1]][cor[i][j][0]] = price[i][j];
                // cout << "edge " << i << " " << j << " connects " << cor[i][j][0] << " and " << cor[i][j][1] << " with " << price[i][j] << '\n';
            }
        }
    }
    // for (int i = 0; i <=m; i ++) {
    //     for (int j = i + 1; j <= m; j ++) {
    //         cout << i << " " << j<< ": " << wall[i][j] << '\n';
    //     }
    // }
    
    vector <int> pen, penp;
    int ans = INF;
    for (int i = 0; i <= m; i ++) {
        // fill(dij, dij + m + 1, INF);
        for (int j = 0; j <= m; j ++) {
            dij[j] = wall[i][0] + wall[j][0];
            par[j] = 0;
        }
        dij[i] = 0, par[i] = par[0] = i;
        pen.clear();
        pen.pb(i);
        while (pen.size()) {
            penp.clear();
            for (int j = 0; j < pen.size(); j ++) {
                for (int k = 1; k <= m; k ++) {
                    if (dij[k] > dij)
                }
                for (int k = 0; k < v[pen[j]].size(); k ++) {
                    if (dij[v[pen[j]][k]] > dij[pen[j]] + wall[v[pen[j]][k]][pen[j]]) {
                        par[v[pen[j]][k]] = pen[j];
                        dij[v[pen[j]][k]] = dij[pen[j]] + wall[v[pen[j]][k]][pen[j]];
                        penp.pb(v[pen[j]][k]);
                    }
                }
            }
            pen = penp;
        }
        fill(mark, mark + m + 1, false);
        int ansp = 0;
        mark[i] = true;
        for (int j = 1; j <= m; j ++) {
            if (j != i && !mark[j]) {
                ansp += dij[j];
                int ind = j;
                while (!mark[ind]) {
                    mark[ind] = true;
                    ind = par[ind];
                }
                ansp -= dij[ind];
            }
        }
        cout << i << ": " << ansp << '\n';
        ans = min(ans, ansp);
    }
    cout << ans << endl;
    return 0;
}
 
/*
4
3 1 2 3 7 4 6
4 1 2 4 5 7 7 2 6
4 4 7 6 5 4 8 9 2
5 3 2 4 7 8 4 7 4 7 7
*/