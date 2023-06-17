//00:52:09; wtf is this, no more ideas
//00:46:18; done
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

const int MAXN = 2.5e4 + 10;
int r;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> r;
    while (r) {
        int ans, sq;
        ans = 0, sq = r * r;
        for (int i = -1 * r; i <= r; i ++) {
            int num = sq - i * i;
            if (num) ans += 2 * (int)sqrt(num); 
            ans ++;
            // cout << i << ": " << num << " " << sqrt(num) << " " << ans << '\n';
        }
        cout << ans << '\n';
        cin >> r;
    }
    return 0;
}
 
/*
    
*/