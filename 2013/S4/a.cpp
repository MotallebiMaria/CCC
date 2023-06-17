//00:32:47; done; tle5
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

const int MAXN = 1e6 + 10;
int n, m, p, q;
vector <int> v[MAXN];
bool vis[MAXN];

bool bfs(int src, int dest) {
    queue <int> q; q.push(src);
    vis[src] = true;
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int x : v[cur]) {
            if (x == dest) return true;
            if (!vis[x]) {
                q.push(x);
                vis[x] = true;
            }
        }
    }
    return false;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    cin >> p >> q;
    if (bfs(p, q))
        cout << "yes";
    else if (bfs(q, p))
        cout << "no";
    else
        cout << "unknown";
    cout << endl;
    return 0;
}
 
/*
    
*/