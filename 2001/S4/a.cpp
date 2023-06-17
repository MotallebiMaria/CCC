//00:27:23
//done
//tc4
//-00:16:23; didn't understand solution in problems doc
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9

const int MAXN = 1e2 + 10;
int n;
pair <double, double> p[MAXN];

double dis(int a, int b, int c, int d) {
    double out = abs(a - c) * abs(a - c);
    out += abs(b - d) * abs(b - d);
    out = sqrt(out);
    return out;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("cookie.in", "r", stdin); freopen("cookie.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    double w = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            w = max(w, dis(p[i].first, p[i].second, p[j].first, p[j].second));
        }
    }
    cout << setprecision(2) << fixed << w << endl;
    // int l, r, u, d;
    // l = d = r = u = 0;
    // for (int i = 0; i < n; i ++) {
    //     if (p[i].first < p[l].first) l = i;
    //     if (p[i].first > p[r].first) r = i;
    //     if (p[i].second < p[d].second) d = i;
    //     if (p[i].second > p[u].first) u = i;
    // }
    // double wh = max(r - l, u - d);
    // double dr = sqrt(wh * wh + wh * wh);
    // cout << setprecision(2) << fixed << dr << endl;
    return 0;
}
 
/*
    
*/