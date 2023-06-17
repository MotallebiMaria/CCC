//
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

class cell {
    public:
    ll r;
    ll c;
};

const int MAXN = 1e3 + 10, MAXA = 1e6 + 10;
int m, n, a[MAXN][MAXN];
vector <cell> v[MAXA];
bool vis[MAXN][MAXN];

cell make_cell(pair <int, int> p) {
    cell cl; cl.r = p.first; cl.c = p.second;
    return cl;
}

string bfs(cell dest) {
	queue <cell> q; q.push(dest);
	vis[dest.r][dest.c] = true;
	while (q.size()) {
		cell cl = q.front();
		q.pop();
        for (cell nei : v[cl.r * cl.c]) {
            if (nei.r == 1 && nei.c == 1) return "yes";
            if (!vis[nei.r][nei.c]) {
                vis[nei.r][nei.c] = true;
                q.push(nei);
            }
        }
	}
    return "no";
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i ++ ) {
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            v[a[i][j]].pb(make_cell(mp(i, j)));
        }
    }
    cout << bfs(make_cell(mp(1,1))) << endl;
    return 0;
}
 
/*
    
*/