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

const int MAXN = 2e3 + 10;
int n, m;
pair <ll, ll> fw[MAXN][MAXN];
bool con[MAXN][MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n>> m;
    for (int i = 0; i < m; i ++) {
        ll u, v, l, c;
        cin >> u >> v >> l >> c;
        fw[u][v] = fw[v][u] = mp(l, c);
        con[u][v] = con[v][u] = true;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (con[i][j]) {
                
            }
        }
    }
    return 0;
}
 
/*
    
*/