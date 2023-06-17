//00:19:58; time's up
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

int n, m, p, q;
// map <pair <int, int>, vector <pair <pair <int, int>, int>>> e;
vector <pair <int, pair <int, int>>> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m >> p >> q;
    for (int i = 0; i < p; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = 1; j <= n; j ++) {
            v.pb(mp(c, mp(j, a)));
            v.pb(mp(c, mp(j, b)));
            // e[mp(j, a)].pb(mp(mp(j, b), c));
            // e[mp(j, b)].pb(mp(mp(j, a), c));
        }
    }
    for (int i = 0; i < q; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        for (int j = 1; j <= n; j ++) {
            v.pb(mp(z, mp(x, j)));
            v.pb(mp(z, mp(y, j)));
            // e[mp(x, j)].pb(mp(mp(y, j), z));
            // e[mp(y, j)].pb(mp(mp(x, j), z));
        }
    }

    return 0;
}
 
/*
    
*/