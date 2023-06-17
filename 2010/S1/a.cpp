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
 
int n;
vector <pair <ll, string>> v;

bool comp(pair <ll, string> a, pair <ll, string> b) {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    if (a.second < b.second) return false;
    return true;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        string s;
        int r, c, d;
        cin >> s >> r >> c >> d;
        v.pb(mp(2 * r + 3 * c + d, s));
    }
    sort(all(v), comp);
    // for (int i = 0; i < v.size(); i ++) {
    //     cout << v[i].second << ": " << v[i].first << '\n';
    // }
    reverse(all(v));
    for (int i = 0; i < min(2, n); i ++) {
        cout << v[i].second << '\n';
    }
    cout << endl;
    return 0;
}
 
/*
4
ABC 13 22 1
DEF 10 20 30
GHI 11 2 2
JKL 20 20 20
*/