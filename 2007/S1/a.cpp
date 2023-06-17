//00:08:20; done
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
 
int n;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s1.in", "r", stdin); freopen("s1.out", "w", stdout);
    cin >> n;
    while (n --) {
        int y, m, d;
        cin >> y >> m >> d;
        string ans = "No";
        if (y <= 1988 || (y == 1989 && (m == 1 || (m == 2 && d <= 27))))
            ans = "Yes";
        cout << ans << endl;
    }
    return 0;
}
 
/*
    
*/