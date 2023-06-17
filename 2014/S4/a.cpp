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
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

class Glass {
    public:
    ll xl;
    ll yt;
    ll xr;
    ll yb;
    ll t;
};

const int MAXN = 1e3 + 10;
int n;
ll T;
Glass g[MAXN];
bool mark[MAXN];
vector <ll> x;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> T;
    for (int i = 0; i < n; i ++) {
        cin >> g[i].xl >> g[i].yt >> g[i].xr >> g[i].yb >> g[i].t;
        x.pb(g[i].xl); x.pb(g[i].xr);
    }
    sort(all(x));
    vector <ll> xp;
    xp.pb(x[0]);
    for (int i = 1; i < x.size(); i ++) {
        if (x[i] != x[i - 1]) {
            xp.pb(x[i]);
        }
    }
    x = xp;
    ll ans = 0;
    for (int i = 1; i < x.size(); i ++) {
        vector <pair <ll, ll>> y;
        for (int j = 0; j < n; j ++) {
            if (x[i - 1] >= g[j].xl && x[i] <= g[j].xr) {
                y.pb(mp(g[j].yt, g[i].t));
                y.pb(mp(g[j].yb, g[i].t * -1));
            }
        }
        sort(all(y));
        vector <pair <ll, ll>> yp;
        yp.pb(y[0]);
        for (int j = 1; j < y.size(); j ++) {
            if (y[j].first == yp.back().first && y[j].second * yp.back().second > 0)
                yp.back().second += y[j].second;
            else yp.pb(y[j]);
        }
        y = yp;
        ll w = x[i] - x[i - 1] + 1;
        ll sum = y[0].second;
        for (int j = 1; j < y.size(); j ++) {
            if (y[j].second < 0) {
                sum += y[j].second;
                continue;
            }
            sum += y[j].second;
            if (sum >= T) {
                ans += w * (y[j].first - y[j - 1].first);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/