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
#define corners(x, y) min(x, y), max(x, y)

class Edge {
    public:
    int cor1;
    int cor2;
    int cost;
};

Edge make_edge(int c1, int c2, int co) {
    Edge res;
    res.cor1 = c1; res.cor2 = c2; res.cost = co;
    return res;
}

const int MAXN = 1e3 + 10;
int m, cor[MAXN][10], price[MAXN][10];
vector <Edge> e[MAXN];
vector <pair <int, pair <int, int>>> v;
map <pair <int, int>, pair <int, int>> con;
bool mark[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> m;
    for(int i = 1; i <= m; i ++) {
        int k, prev;
        cin >> k >> prev;
        for (int j = 0; j < k; j ++) cin >> cor[i][j];
        for (int j = 0; j < k; j ++) cin >> price[i][j];
        for (int j = 0; j < k - 1; j ++) {
            e[i].pb(make_edge(corners(cor[i][j], cor[i][j + 1]), price[i][j]));
        }
        e[i].pb(make_edge(cor[i][k - 1], cor[i][0], price[i][k - 1]));
    }
    for (int i = 1; i <= m; i ++) {
        for (int j = 0; j < e[i].size(); j ++) {
            if (con[mp(corners(e[i][j].cor1, e[i][j].cor2))].first == -1)
                con[mp(corners(e[i][j].cor1, e[i][j].cor2))].first = i;
            else
                con[mp(corners(e[i][j].cor1, e[i][j].cor2))].second = i;
        }
    }
    for (int i = 1; i <= 1e3; i ++) {
        for (int j = 1; j <= 1e3; j ++) {
            if (con[mp(i, j)] != mp(-1, -1)) {
                if (con[mp(i, j)].first != -1 && con[mp(i, j)].second != -1) {
                    v.pb(mp())
                }
            }
        }
    }
    return 0;
}
 
/*
    4
    3 1 2 3 7 4 6
    4 1 2 4 5 7 7 2 6
    4 4 7 6 5 4 8 9 2
    5 3 2 4 7 8 4 7 4 7 7
*/