//00:03:03; done; accepted
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
 
int k;
vector <int> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> k;
    while (k --) {
        int x;
        cin >> x;
        if (x) v.pb(x);
        else v.pop_back();
    }
    ll sum = 0;
    for (int i = 0; i < v.size(); i ++) {
        sum += v[i];
    }
    cout << sum << endl;
    return 0;
}
 
/*
    
*/