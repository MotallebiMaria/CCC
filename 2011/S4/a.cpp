//
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
 
int bl[5][5]; // 00o- 01o+ 10a- 11a+ 20b- 21b+ 30ab- 31ab+
int p[5][5];
int ans;

void give(int g, int r) {
    int num = min(bl[g][0], p[r][0]);
    ans += num, p[r][0] -= num, bl[g][0] -= num;
    num = min(bl[g][1], p[r][1]);
    ans += num, p[r][1] -= num, bl[g][1] -= num;
    num = min(bl[g][0], p[r][1]);
    ans += num, p[r][1] -= num, bl[g][0] -= num;
    return;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    for (int i = 0; i < 4; i ++) {
        cin >> bl[i][0] >> bl[i][1];
    }
    for (int i = 0; i < 4; i ++) {
        cin >> p[i][0] >> p[i][1];
    }
    give(3, 3); give(1, 1); give(1, 3); give(2, 2); give(2, 3);
    give(0, 0); give(0, 1); give(0, 2); give(0, 3);
    cout << ans << endl;
    return 0;
}
 
/*
    
*/