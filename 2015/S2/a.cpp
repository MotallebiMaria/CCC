//00:06:29; done; accepted
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

const int MAXN = 1e6 + 10;
int j, a, an[MAXN];
char js[MAXN], as[MAXN];
bool mark[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> j >> a;
    for (int i = 1; i <= j; i ++) cin >> js[i];
    for (int i = 1; i <= a; i ++) cin >> as[i] >> an[i];
    int ans = 0;
    for (int i = 1; i <= a; i ++) {
        if (!mark[an[i]] && js[an[i]] <= as[i]) {
            ans ++;
            mark[an[i]] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/