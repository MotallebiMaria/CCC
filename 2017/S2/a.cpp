//00:12:58; done; 15/15
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

const int MAXN = 1e2 + 10;
int n, a[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    sort(a, a + n);
    int low, high;
    low = n / 2 - (n + 1) % 2; high = low + 1;
    for (int i = 0; i < n; i ++) {
        if (i % 2)
            cout << a[high ++];
        else
            cout << a[low --];
        cout << " ";
    }
    cout << endl;
    return 0;
}
 
/*
    
*/