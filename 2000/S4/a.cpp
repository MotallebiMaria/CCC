//01:43:28
//tc2:5
//note: attention to detail ("didn't include defeat")
//used recursion and time limit
//figured out dp; trying to implement it
//43 min; solved
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
int d, c, cd[MAXN], dp[MAXN][50], ans[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("golf.in", "r", stdin); freopen("golf.out", "w", stdout);
    cin >> d >> c;
    for (int i = 0; i < c; i ++) {
        cin >> cd[i];
    }
    for (int i = 0; i <= d; i ++) {
        fill(dp[i], dp[i] + 40, INF);
    }
    fill(ans, ans + MAXN, INF);
    ans[0] = 0;
    for (int i = 1; i <= d; i ++) {
        for (int j = 0; j < c; j ++) {
            if (i - cd[j] >= 0 && ans[i - cd[j]] != INF) {
                dp[i][j] = ans[i - cd[j]] + 1;
                ans[i] = min(ans[i], dp[i][j]);
            }
        }
        for (int j = 0; j < c; j ++) {

        }
    }
    if (ans[d] != INF) {
        cout << "Roberta wins in " << ans[d] << " strokes." << endl;
    }
    else {
        cout << "Roberta acknowledges defeat." << endl;
    }
    return 0;
}
 
/*
    
*/