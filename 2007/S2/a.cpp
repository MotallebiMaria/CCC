//00:09:32; done
//mistake1: needed to make it minimum
//00:02:36; mistake1 fixed
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
 
const int MAXN= 1e3 + 10;
int n, m, b1[MAXN], b2[MAXN], b3[MAXN], p1[MAXN],p2[MAXN], p3[MAXN], v[MAXN];

bool fits(int a, int b, int c, int x, int y, int z) {
    if (a <= x && b <= y && c <= z) return true;
    if (a <= x && c <= y && b <= z) return true;
    if (b <= x && a <= y && c <= z) return true;
    if (b <= x && c <= y && a <= z) return true;
    if (c <= x && a <= y && b <= z) return true;
    if (c <= x && b <= y && a <= z) return true;
    return false;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s2.in", "r", stdin); freopen("s2.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n ; i ++) cin >> b1[i] >> b2[i] >> b3[i];
    cin >> m;
    for (int i = 0; i < m; i ++) cin >> p1[i] >> p2[i] >> p3[i];
    for (int i= 0; i < n; i ++) {
        v[i] = b1[i] * b2[i] * b3[i];
    }
    for (int i = 0 ; i < m; i ++) {
        int ind = -1;
        for (int j = 0; j < n; j ++) {
            if (fits(p1[i], p2[i], p3[i], b1[j], b2[j], b3[j]) && (ind == -1 || v[j] < v[ind])) {
                ind = j;
            }
        }
        if (ind == -1) {
            cout << "Item does not fit\n";
        }
        else {
            cout << v[ind] << '\n';
        }
    }
    return 0;
}
 
/*
    
*/