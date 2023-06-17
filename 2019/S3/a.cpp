//00:45:49; will come back
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
#define INF (int)1e9 + 1
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

ll a[3][3], cntr[10], cntc[10], ap[3][3], cnt;

int toInt(string x) {
    int out = 0;
    int tens = 1;
    for (int i = 0; i < x.size(); i ++) {
        if (i == 0 && x[i] == '-') continue;
        out = out * tens + x[i] - '0';
        tens *= 10;
    }
    if (x[0] == '-') out *= -1;
    return out;
}

void complete2(int x) {
    if (cntr[x] == 2) {
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {

            }
        }
    }
    if (cntc[x] == 2) {

    }
}

void solve() {
    while (cnt < 9) {
        bool b = false;
        for (int i = 0; i < 3; i ++) {
            if (cntr[i] == 2 || cntc[i] == 2) {
                complete2(i);
            }
        }
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            string s;
            cin >> s;
            if (s == "X") a[i][j] = INF;
            else a[i][j] = toInt(s), cntr[i] ++, cntc[j] ++, cnt ++;
        }
    }
    if (cnt < 2) {
        ll num = INF - 1;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                num = min(num, a[i][j]);
            }
        }
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                cout << num << " ";
            }
            cout << '\n';
        }
        return 0;
    }
    if (cnt == 2 && max(cntr[0], max(cntr[1], cntr[2])) == 1 && max(cntc[0], max(cntc[1], cntc[2])) == 1) {
        vector <pair <int, int>> v;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                ap[i][j] = a[i][j];
                if (a[i][j] != INF) v.pb(mp(i, j));
            }
        }
        int num = 1;
        if (a[v[0].first][v[0].second] % 2 == a[v[1].first][v[1].second] % 2)
            num = 2;
        if (v[0].first == 0) {
            a[1][v[0].second] = a[0][v[0].second] + num;
            a[2][v[0].second] = a[0][v[0].second] + num * 2;
        }
        else if (v[0].first == 1) {
            a[0][v[0].second] = a[1][v[0].second] - num;
            a[2][v[0].second] = a[1][v[0].second] + num;
        }
        else {
            a[0][v[0].second] = a[1][v[0].second] - num * 2;
            a[1][v[0].second] = a[1][v[0].second] - num;
        }
    }
    solve();
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    cout << endl;
    return 0;
}
 
/*
    
*/