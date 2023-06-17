//00:18:56; done; 15/15
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
#define MOD (int)1e9 + 7
#define EPS 1e-9
#define DBG(var) cerr << #var << " = " << var << endl;

const int MAXN = 1e2 + 10;
int n, a[MAXN][MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
        }
    }
    bool good = true;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if ((i && a[i][j] < a[i - 1][j]) || (j && a[i][j] < a[i][j - 1])) {
                good = false;
                break;
            }
        }
    }
    if (good) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
        cout << endl;
        return 0;
    }

    good = true;
    for (int i = 0; i < n; i ++) {
        for (int j = n - 1; j >= 0; j --) {
            if ((i && a[j][i] < a[j][i - 1]) || (j < n - 1 && a[j][i] < a[j + 1][i])) {
                good = false;
                break;
            }
        }
    }
    if (good) {
        for (int i = 0; i < n; i ++) {
            for (int j = n - 1; j >= 0; j --) {
                cout << a[j][i] << " ";
            }
            cout << '\n';
        }
        cout << endl;
        return 0;
    }
    
    good = true;
    for (int i = n - 1; i >= 0; i --) {
        for (int j = n - 1; j >= 0; j --) {
            if ((i < n - 1 && a[i][j] < a[i + 1][j]) || (j < n - 1 && a[i][j] < a[i][j + 1])) {
                good = false;
                break;
            }
        }
    }
    if (good) {
        for (int i = n - 1; i >= 0; i --) {
            for (int j = n - 1; j >= 0; j --) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
        cout << endl;
        return 0;
    }
    
    for (int i = n - 1; i >= 0; i --) {
        for (int j = 0; j < n; j ++) {
            cout << a[j][i] << " ";
        }
        cout << '\n';
    }
    cout << endl;
    return 0;
}
 
/*
    
*/