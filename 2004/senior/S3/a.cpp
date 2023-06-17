//00:36:00
//-00:14:54
//done
//solved
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
 
const int MAXN = 1e2 + 10;
int val[MAXN][MAXN];
vector <pair <int, int>> par[MAXN][MAXN];
bool used[MAXN][MAXN];

int f(int x, int y) {
    // cout << x << ", " << y << endl;
    int sum = 0;
    for (int i = 0; i < par[x][y].size(); i ++) {
        int a, b;
        a = par[x][y][i].first, b = par[x][y][i].second;
        if (used[a][b]) return -1;
        if (val[a][b] == INF) {
            used[a][b] = true;
            val[a][b] = f(a, b);
            used[a][b] = false;
        }
        if (val[a][b] == -1) return -1;
        sum += val[a][b];
    }
    return sum;
}

int toInt(string s) {
    int ten = 1;
    int out = 0;
    for (int i = s.size() - 1; i >= 0; i --) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            out = INF;
            break;
        }
        out += (s[i] - '0') * ten;
        ten *= 10;
    }
    return out;
}

void pars(int x, int y, string s) {
    int a, b;
    a = b = 0;
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            a = s[i] - 'A';
        }
        else if (s[i] >= '1' && s[i] <= '9') {
            b = s[i] - '1';
            par[x][y].pb(mp(a, b));
        }
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("spread.in", "r", stdin); freopen("spread.out", "w", stdout);
    for (int i = 0; i < 10; i ++) {
        fill(val[i], val[i] + 9, INF);
        for (int j = 0; j < 9; j ++) {
            string s;
            cin >> s;
            val[i][j] = toInt(s);
            if (val[i][j] == INF) {
                pars(i, j, s);
            }
        }
    }
    // for (int i = 0; i < 10; i ++) {
    //     for (int j = 0; j < 9; j ++) {
    //         if (par[i][j].size()) {
    //             cout << i << "," << j << ": ";
    //             for (int k = 0; k < par[i][j].size(); k ++) {
    //                 cout << par[i][j][k].first << "," << par[i][j][k].second << " ";
    //             }
    //             cout << '\n';
    //         }
    //     }
    // }
    // cout << endl;
    for (int i = 0 ; i < 10; i ++) {
        for (int j = 0; j < 9; j ++) {
            if (val[i][j] == INF) {
                used[i][j] = true;
                val[i][j] = f(i, j);
                used[i][j] = false;
            }
        }
    }
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 9; j ++) {
            if (val[i][j] == -1)
                cout << "* ";
            else
                cout << val[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
 
/*
    
*/