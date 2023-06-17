//00:09:44
//done
//solved
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
 
int c, r;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s2.in", "r", stdin); freopen("s2.out", "w", stdout);
    cin >> c >> r;
    int x, y;
    x = y = 0;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (!a && !b) break;
        x += a, y += b;
        // cout << x << " " << y << " ";
        x = max(x, 0), y = max(y, 0);
        x = min(x, c), y = min(y, r);
        cout << x << " " << y << '\n';
    }
    return 0;
}
 
/*
    
*/