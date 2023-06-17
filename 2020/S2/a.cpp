//00:21:45; done; 7/15
//00:08:39; done; 0/15
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
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

const int MAXN = 1e3 + 10, MAXA = 1e6 + 10;
int m, n, a[MAXN][MAXN];
vector <pair <int, int>> v[MAXA];
string ans[MAXN][MAXN];

string hehe(int x, int y) {
    if (ans[x][y] != "hehe") return ans[x][y];
    int num = x * y;
    for (int i = 0; i < v[num].size(); i ++) {
        if (hehe(v[num][i].first, v[num][i].second) == "yes")
            return ans[x][y] = ans[y][x] = "yes";
    }
    return ans[x][y] = ans[y][x] = "no";
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    // for (int i = 2; i <= 1e6; i ++) {
    //     for (int j = 1; j * j <= i; j ++) {
    //         if (i % j == 0) {
    //             v[i].pb(mp(i / j, j));
    //             if (i / j != j)
    //                 v[i].pb(mp(j, i / j));
    //         }
    //     }
    // }
    cin >> m >> n;
    for (int i = 1; i <= m; i ++ ) {
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            v[a[i][j]].pb(mp(i, j));
            ans[i][j] = "hehe";
        }
    }
    ans[1][1] = "yes";
    cout << hehe(m, n) << endl;
    return 0;
}
 
/*
    
*/