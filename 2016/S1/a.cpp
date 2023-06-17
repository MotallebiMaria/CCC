//00:05:34; done; accepted
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
 
string a, b;
int cnta[30], cntb[30];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> a >> b;
    for (int i = 0; i < a.size(); i ++) {
        cnta[a[i] - 'a'] ++;
    }
    int cnt = 0;
    for (int i = 0; i < b.size(); i ++) {
        if (b[i] != '*') cntb[b[i] - 'a'] ++;
    }
    for (int i = 0; i < 26; i ++) {
        if (cntb[i] > cnta[i]) {
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "A" << endl;
    return 0;
}
 
/*
    
*/