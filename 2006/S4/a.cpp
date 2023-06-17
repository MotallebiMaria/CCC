//00:42:13; done
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
int n, a[MAXN][MAXN];
bool mr[MAXN][MAXN], mc[MAXN][MAXN];
vector <int> vr[MAXN], vc[MAXN], idn, idn2;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s4.in", "r", stdin); freopen("s4.out", "w", stdout);
    cin >> n;
    while (n) {
        for (int i = 1; i <= n; i ++) {
            fill(mr[i], mr[i] + n, false);
            fill(mc[i], mc[i] + n, false);
            vr[i].clear(); vc[i].clear();
        }
        idn.clear(); idn2.clear();
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                cin >> a[i][j];
                mr[i][a[i][j]] = true;
                mc[j][a[i][j]] = true;
                vr[a[i][j]].pb(i);
                vc[a[i][j]].pb(j);
            }
        }
        string ans = "yes";
        for (int i = 1; i <= n; i ++) {
            if (vr[i].size() == n && vc[i].size() == n) {
                idn.pb(i);
            }
        }
        for (int i = 0; i < idn.size(); i ++) {
            bool isIdn = true;
            int x = idn[i];
            for (int j = 1; j <= n; j ++) {
                if (!(a[x][j] == j && a[j][x] == j)) {
                    isIdn = false;
                    break;
                }
            }
            if (isIdn) idn2.pb(x);
        }
        if (idn2.empty()) ans = "no";
        for (int i = 1; i <= n ; i ++) {
            for (int j = 1; j <= n; j ++) {
                for (int k = 1; k <= n; k ++) {
                    if (a[a[i][j]][k] != a[i][a[j][k]]) {
                        ans = "no";
                        break;
                    }
                }
                if (ans == "no") break;
            }
            if (ans == "no") break;
        }
        cout << ans << '\n';
        cin >> n;
    } 
    return 0;
}
 
/*
    
*/