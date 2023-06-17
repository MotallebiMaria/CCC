//00:09:25; done
//ridiculously large number of inputs for tc's 4 & 5; was unable to fully check
//right answer for tc's 1:3
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
 
const int MAXN = 2e6 + 10;
int n;
pair <int, int> p[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int r;
        cin >> r;
        p[r].first ++;
        p[r].second = r;
    }
    sort(p, p + MAXN); reverse(p, p + MAXN);
    int ans = p[0].second;
    if (p[0].first == p[1].first) {
        int num = p[1].second;
        for (int i = 2; i < MAXN; i ++) {
            if (p[i].first != p[0].first) break;
            num = p[i].second;
        }
        ans -= num;
    }
    else {
        ans = abs(ans - p[1].second);
        for (int i = 1; i < MAXN; i ++) {
            if (p[i].first != p[1].first) break;
            ans = max(ans, p[0].second - p[i].second);
        }
    }
    cout << ans << endl;
    return 0;
}
 
/*
    
*/