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

const int MAXN = 1e5 + 10;
int n, m, pho[MAXN];
bool ispho[MAXN], used[MAXN];
vector <int> v[MAXN];
vector <pair <int, int>> e;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> pho[i];
        ispho[pho[i]] = true;
    }
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b); v[b].pb(a);
        if (ispho[a]) e.pb(mp(a, b));
    }
    ll sum = 0;
    sort(all(e));
    for (int i = 0; i < e.size(); i ++) {
        if (!used[e[i].first] || !used[e[i].second]) {
            sum ++;
        }
    }
    return 0;
}
 
/*
    
*/