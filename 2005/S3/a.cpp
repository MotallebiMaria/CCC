//00:36:00
//-00:05:23
//done
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
 
const int MAXN = 1e3 + 50;
int t, a[MAXN][MAXN], b[MAXN][MAXN], x[MAXN][MAXN];
int mxe, mne, rs[MAXN], cs[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s3.in", "r", stdin); freopen("s3.out", "w", stdout);
    cin >> t;
    t --;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> a[i][j];
        }
    }
    while (t--) {
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                cin >> x[i][j];
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                for (int k = 0; k < r; k ++) {
                    for (int l = 0; l < c; l ++) {
                        b[i * r + k][j * c + l] = a[i][j] * x[k][l];
                    }
                }
            }
        }
        n *= r, m *= c;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                a[i][j] = b[i][j];
            }
        }
    }
    mne = mxe = a[0][0];
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            rs[i] += a[i][j];
            cs[j] += a[i][j];
            mne = min(mne, a[i][j]);
            mxe = max(mxe, a[i][j]);
        }
    }
    sort(rs, rs + n);
    sort(cs, cs + m);
    cout << mxe << '\n' << mne << '\n' << rs[n - 1] << '\n' << rs[0] << '\n' << cs[m - 1] << '\n' << cs[0] << endl;
    return 0;
}
 
/*
    
*/