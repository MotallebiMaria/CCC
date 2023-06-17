//00:27:52; done
//all wa
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
 
const int MAXN = 1e2 + 10;
double r[5], J[5];
int n, ans;
vector <pair <double, double>> v[MAXN];

double intersect(double m1, double b1, double m2, double b2) {
    if (m1 == m2) return INF;
    double x = (m1 - m2) / (b2 - b1);
    return x;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s3.in", "r", stdin); freopen("s3.out", "w", stdout);
    cin >> r[0] >> r[1] >> J[0] >> J[1] >> n;
    for (int i = 0; i < n; i ++) {
        int num;
        cin >> num;
        v[i].pb(mp(0, 0));
        while (num --) {
            v[i].pb(mp(0, 0));
            cin >> v[i].back().first >> v[i].back().second;
        }
        v[i][0] = v[i].back();
    }
    double m = (r[1] - J[1]) / (r[0] - J[0]);
    double b = r[1] - m * r[0];
    for (int i = 0; i < n; i ++) {
        bool hehe = false;
        for (int j = 1; j < v[i].size(); j ++) {
            if (m * v[i][j].first + b == v[i][j].second) {
                hehe = true;
                break;
            }
            double x, y, z, w;
            x = v[i][j].first, y = v[i][j].second, z = v[i][j - 1].first, w = v[i][j - 1].second;
            double m2, b2;
            m2 = (y - w) / (x - z); b2 = y - m2 * x;
            double huh = intersect(m, b, m2, b2);
            if (huh >= min(r[0], J[0]) && huh <= max(r[1], J[1])) {
                hehe = true;
                break;
            }
        }
        if (hehe) ans ++;
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/