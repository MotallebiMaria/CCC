//00:02:00
//-00:13:07
//-00:11:33
//gave up
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
 
using namespace std;
 
typedef long long ll;
 
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define INF (int)1e9
 
const int MAXN = 1e3 + 10;
vector <pair <int, int>> v, ans;
vector <int> e[MAXN];
bool used[MAXN];

void hehe(int x, int l) {
    used[x] = true;
    for (int i = 0; i < e[x].size(); i ++) {
        if (used[e[x][i]]) {
            l --;
        }
    }
    if (l == 0)
    for (int i = 0; i < e[x].size(); i ++) {
        if (!used[e[x][i]]) {
            hehe(e[x][i], l + 1);
        }
    }
    used[x] = false;
    return;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("bomb.in", "r", stdin); freopen("bomb.out", "w", stdout);
    char a, b;
    a = b = 'x';
    while (a != '*') {
        cin >> a >> b;
        if (a == '*') break;
        int A = a - 'A', B = b - 'A';
        v.pb(mp(A, B));
        e[A].pb(B); e[B].pb(A);
    }
    hehe(0, 0);
    return 0;
}
 
/*
    
*/