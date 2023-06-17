//00:52:00; done
//wa4; don't know what the mistake is
//+00:12:00; solved (problem statement said student numbers are <= n but gives more)
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

const int MAXN = 1e4 + 10;
int n, p[MAXN], f[MAXN], d[MAXN];
bool mark[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("s3.in", "r", stdin); freopen("s3.out", "w", stdout);
    cin >> n;
    fill(f, f + 10000, -1);
    for (int i = 1; i <= n; i ++) {
        int a, b;
        cin >> a >> b;
        f[a] = b;
    }
    fill(p, p + 10000, -1);
    for (int i = 1; i <= 9999; i ++) {
        if (f[i] == -1) continue;
        mark[i] = true;
        if (mark[f[i]]) {
            int dis = 0;
            int ind = f[f[i]];
            while (!(ind == f[f[i]] && dis)) {
                p[ind] = f[i];
                d[ind] = dis; dis ++;
                ind = f[ind];
            }
        }
    }
    int a, b;
    cin >> a >> b;
    while (!(a == 0 && b == 0)) {
        // cout << a << ": " << p[a] << " " << d[a] << ", " << b << ": " << p[b] << " " << d[b] << '\n';  
        if (p[a] != p[b] || p[a] == -1 || p[b] == -1) cout << "No\n";
        else {
            cout << "Yes ";
            if ( a == b) cout << d[a];
            else if (d[a] < d[b]) cout << d[b] - d[a] - 1;
            else cout << d[p[a]] - d[a] + d[b];
            cout << '\n';
        }
        cin >> a >> b;
    }
    return 0;
}
 
/*
    
*/