//00:06:54; done
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
 
int a, b;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> a >> b;
    int cnta, cntb; cnta = cntb= 0;
    for (int i = 1; pow(i, 6) < a; i ++) cnta ++;
    for (int i = 1; pow(i, 6) <= b; i ++) cntb ++;
    cout << cntb - cnta << '\n';
    return 0;
}
 
/*
    
*/