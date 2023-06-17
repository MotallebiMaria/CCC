//00:50:00??
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

const int MAXN = 1.5e5 + 10;
int n, m, mlt[MAXN][20], dvd[MAXN][20], num[MAXN];
vector <int> v[MAXN], vp[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].pb(z); vp[y + 1].pb(z);
        int zp = z;
        for (int j = 2; j * j <= zp; j ++) {
            int cnt = 0;
            while (zp % j == 0) {
                cnt ++;
                zp /= j;
            }
            mlt[x][j] += cnt - min(cnt, mlt[x][j]);
            dvd[y + 1][j] += cnt - min(cnt, dvd[y + 1][j]);
        }
        if (zp > 1) {
            mlt[x][zp] += 1 - min(1, mlt[x][zp]);
            dvd[y + 1][zp] += 1 - min(1, dvd[y + 1][zp]);
        }
    }
    ll num = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            if (v[i][j] < 0) num /= v[i][j];
        }
        for (int j = 0; j < v[i].size(); j ++) {
            if (v[i][j] > 0 && )
        }
    }
    return 0;
}
 
/*
    
*/