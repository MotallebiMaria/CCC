//00:05:01; done
//accepted
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

const int MAXN = 1e5 + 10;
int mw, n, w[MAXN];
ll ps[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> mw >> n;
    for (int i =1 ; i <= n; i++) {
        cin >> w[i];
        ps[i] = ps[i - 1] + w[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (ps[i] - ps[max(i - 4, 0)] > mw) break;
        ans = i;
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/