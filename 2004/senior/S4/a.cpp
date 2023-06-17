//00:31:24
//gave up
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
 
double s[3], t[3];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; i ++) cin >> s[i];
    for (int i = 0; i < 3; i ++) cin >> t[i];
    double ans = hypot(abs(s[2] - t[2]), hypot(abs(s[0] - t[0]), abs(s[1] - t[1])));
    int dir, n;
    dir = n = 0;
    char c = 'x';
    while (c != 'E') {
        cin >> n >> c;
        if (c == 'E') break;
        if (c == 'L') {
            if (dir < 4) {
                dir --;
                if (dir < 0) dir += 4;
            }
            else if (dir == 4) dir = 0;
            else dir = 2;
        }
        else if (c == 'R') {
            if (dir < 4) dir = (dir + 1) % 4;
            else if (dir == 4) dir = 2;
            else dir = 0;
        }
        else if (c == 'U') {
            if (dir < 4) dir = 4;

        }
        if (dir == 0) s[0] += n;
        else if (dir == 1) s[1] += n;
        else if (dir == 2) s[0] -= n;
        else if (dir == 3) s[1] -= n;
        else if (dir == 4) s[2] += n;
        else s[2] -= n;
        ans = min(ans, hypot(abs(s[2] - t[2]), hypot(abs(s[0] - t[0]), abs(s[1] - t[1]))));
    }
    return 0;
}
 
/*
    
*/