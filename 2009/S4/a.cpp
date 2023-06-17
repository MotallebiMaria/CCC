//00:19:32; done
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
 
const int MAXN = 5e3 + 10;
int n, t, k, d, p[MAXN], dfs[MAXN];
vector <pair <int, int>> v[MAXN];
vector <int> cit, citp;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> t;
    for (int i = 0; i < t; i ++) {
        int x, y, c;
        cin >> x >> y >> c;
        v[x].pb(mp(y, c)); v[y].pb(mp(x, c));
    }
    cin >> k;
    fill(p, p + n + 1, -1);
    for (int i = 0; i < k; i ++) {
        int z, pz;
        cin >> z >> pz;
        p[z] = pz;
    }
    cin >> d;
    fill(dfs, dfs + n + 1, -1);
    cit.pb(d);
    dfs[d] = 0;
    while (cit.size()) {
        citp.clear();
        for (int i = 0; i < cit.size(); i ++) {
            for (int j = 0; j < v[cit[i]].size(); j ++) {
                if (dfs[v[cit[i]][j].first] != -1) continue;
                citp.pb(v[cit[i]][j].first);
                dfs[v[cit[i]][j].first] = dfs[cit[i]] + v[cit[i]][j].second;
            }
        }
        cit = citp;
    }
    int ind = 1;
    for (int i = 1; i <= n; i ++) {
        if (p[i] != -1 && dfs[i] + p[i] < dfs[ind] + p[ind])
            ind = i;
    }
    cout << dfs[ind] + p[ind] << endl;
    return 0;
}
 
/*
    d: dfs root
    min p[i] + dfs[i]
*/