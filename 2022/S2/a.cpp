//00:12:02; done; 15/15
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
int x, y, g;
pair <string, string> must[MAXN], no[MAXN];
map <string, pair <string, string>> m;

bool sameg(pair <string, string> p) {
    string a, b; a = p.first, b = p.second;
    return (m[a].first == b || m[a].second == b);
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> x;
    for (int i = 0; i < x; i ++) cin >> must[i].first >> must[i].second;
    cin >> y;
    for (int i = 0; i < y; i ++) cin >> no[i].first >> no[i].second;
    cin >> g;
    for (int i = 0; i < g; i ++) {
        string a, b, c;
        cin >> a >> b >> c;
        m[a] = mp(b, c);
        m[b] = mp(a, c);
        m[c] = mp(a, b);
    }
    int ans = 0;
    for (int i = 0; i < x; i ++) {
        if (!sameg(must[i])) {
            ans ++;
            // cout << must[i].first << " " << must[i].second << " not in sameg\n";
        }
    }
    for (int i = 0; i < y; i ++) {
        if (sameg(no[i])) {
            ans ++;
            // cout << no[i].first << " " << no[i].second << " in sameg\n";
        }
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/