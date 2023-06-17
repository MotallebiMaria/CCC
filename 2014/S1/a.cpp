//00:06:36; done
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
 
int k, m;
vector <int> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> k >> m;
    for (int i =1; i <= k; i++) v.pb(i);
    while (m --) {
        int r;
        cin >> r;
        int cnt = 0;
        vector <int> vp;
        for (int i = 0; i < v.size(); i ++) {
            if ((i + 1) % r) vp.pb(v[i]);
        }
        v = vp;
    }
    for (int i = 0; i < v.size(); i ++) {
        cout << v[i] << '\n';
    }
    cout << endl;
    return 0;
}
 
/*
    
*/