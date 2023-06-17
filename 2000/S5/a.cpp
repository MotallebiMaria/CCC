//02:12:30
//tc5 one short
//note: use smallest amount given for step
//15 mins; solved
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9
 
const int MAXN = 1e3 + 10;
int n;
pair <double, double> p[MAXN];
map <double, vector <double>> m;
vector <double> v;
set <pair <double, double>> s;

double dis(double pt, double p2f, double p2s) {
    if (p2f == pt) {
        return p2s;
    }
    else {
        return sqrt(pow(abs(p2f - pt), 2) + pow(p2s, 2));
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("sheep.in", "r", stdin); freopen("sheep.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> p[i].first >> p[i].second;
        v.pb(p[i].first);
    }
    sort(all(v));
    v.resize(distance(v.begin(), unique(all(v))));
    for (double i = 0; i <= 1000; i += 0.01) {
        double mindis = INF;
        for (int j = 0; j < n;j ++) {
            mindis = min(mindis, dis(i, p[j].first, p[j].second)); 
        }
        for (int j = 0; j < n; j ++) {
            if (dis(i, p[j].first, p[j].second) == mindis) {
                s.insert(p[j]);
            }
        }
    }
    for (auto it = s.begin(); it != s.end(); it ++) {
        cout << setprecision(2) << fixed << "The sheep at (" << (*it).first << ", " << (*it).second << ") might be eaten.\n";
    }
    return 0;
}
 
/*
    
*/