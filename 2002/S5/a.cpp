//01:00:00
//-00:12:42
//done
//tc1-3,5
//-01:07:20
//forgot to consider when len negative and go to next sid
//tc2-3,5
//-00:02:49
//-01:10:09
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
#define PI 3.14159265
 
double n, m, p, q;

double toRad(double deg) {
    return (deg * PI) / 180;
}

double toDeg(double rad) {
    return rad * 180 / PI;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("ball.in", "r", stdin); freopen("ball.out", "w", stdout);
    cin >> n >> m >> p >> q;
    if (p == n / 2 && q == m / 2) {
        cout << 0 << endl;
        return 0;
    }
    double deg = atan((n - p) / q);
    double len = m - q;
    int ans, sid;
    ans = sid = 0;
    double lenp = len;
    while (len >= 5) {
        if (sid == 1 && len == lenp) {
            ans = 0;
            break;
        }
        ans ++, sid = (sid + 1) % 4;
        len *= tan(deg);
        deg = toRad(90 - toDeg(deg));
        if (sid % 2) {
            if (len <= n)
                len = n - len;
            else {
                sid ++;
                len -= n;
                len *= tan(deg);
                deg = toRad(90 - toDeg(deg));
            }
        }
        else {
            if (len <= m)
                len = m - len;
            else {
                sid ++;
                len -= m;
                len *= tan(deg);
                deg = toRad(90 - toDeg(deg));
            }
        }
        cout << sid << ": " << len << " " << toDeg(deg) << '\n';
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/