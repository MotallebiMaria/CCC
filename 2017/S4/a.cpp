//00:45:45; 0/15
//00:46:29; 
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
 
const int MAXN = 2e5 + 10;
int n, m, d;
pair <pair <ll, int>, pair <int, int>> p[MAXN];
bool mark[MAXN], active[MAXN];
vector <pair <ll, int>> ans;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m >> d;
    for (int i = 0; i < m; i ++) {
        cin >> p[i].second.first >> p[i].second.second >> p[i].first.first;
        if (i < n - 1) p[i].first.second = 1;
    }
    for (int i = 0; i < m; i ++) {
        ll hold = p[i].first.first;
        int l, r; l = p[i].second.first, r = p[i].second.second;
        p[i].first.first = max(p[i].first.first - d, 0ll);
        sort(p, p + m);
        fill(mark, mark + n + 1, false);
        int ansp = 0;
        ll sum = 0;
        vector <pair <int, int>> cur;
        for (int j = 0; j < m; j ++) {
            if (!mark[p[j].second.first] || !mark[p[j].second.second]) {
                ansp += p[j].first.second ^ 1;
                sum += p[j].first.first;
                cur.pb(mp(p[j].second.first, p[j].second.second));
                mark[p[j].second.first] = mark[p[j].second.second] = true;
            }
        }
        for (int j = 0; j < m; j ++) {
            if (p[j].second.first == l && p[j].second.second == r) {
                p[j].first.first = hold;
                break;
            }
        }
        // cout << i << ": " ;
        // for (int j = 0; j < cur.size(); j ++) {
        //     cout << cur[j].first << "-" << cur[j].second << " ";
        // }
        // cout << ", ";
        // for (int j = 0; j < m; j ++) {
        //     cout << p[j].first.first << " ";
        // }
        // cout << '\n';
        ans.pb(mp(sum, ansp));
    }
    // for (int i = 0; i < ans.size(); i ++) {
    //     cout << "cost " << ans[i].first << " with " << ans[i].second << " days\n";
    // }
    sort(all(ans));
    cout << ans[0].second << '\n';
    return 0;
}
 
/*
    
*/