//00:10:11
//done
//tc2-5
//wtf was i thinking
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

const int MAXN = 1e3 + 10;
int m, q;
pair <int, string> p[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("bridge.in", "r", stdin); freopen("bridge.out", "w", stdout);
    cin >> m >> q;
    for (int i = 0 ; i < q; i ++) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p, p + q);
    int tot, cnt;
    tot = cnt = 0;
    for (int i = 0; i < q; i ++) {
        if ((i && p[i].first != p[i - 1].first) || cnt == m) {
            cout << '\n';
            cnt = 0;
            tot += p[i - 1].first;
        }
        cout << p[i].second << " ";
        cnt ++;
    }
    tot += p[q - 1].first;
    cout << "\nTotal time: " << tot << endl;
    return 0;
}
 
/*
    
*/