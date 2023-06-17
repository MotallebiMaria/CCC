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

const int MAXN = 2e5 + 10;
int n, cnt[MAXN];
vector <pair <int, int>> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    int ans = 1;
    for (int i= 0; i < n; i ++) {
        for (int j = 1; j <= 5; j ++) {
            char c;
            cin >> c;
            if (c == 'Y') cnt[j] ++;
            if (cnt[j] > cnt[ans]) ans = j;
        }
    }
    for (int i = 1; i <= 5; i ++) {
        v.pb(mp(cnt[i], -1 * i));
    }
    sort(all(v)); reverse(all(v));
    cout << v[0].second * -1;
    for (int i = 1; i < v.size(); i ++) {
        if (v[i].first != v[0].first) break;
        cout << "," << -1 * v[i].second;
    }
    cout << '\n';
    return 0;
}
 
/*
    
*/