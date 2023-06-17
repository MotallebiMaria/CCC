//00:08:43; done
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
 
const int MAXN = 1e3 + 10;
string pt, ct, s;
int hehe[MAXN];
 
int32_t main() {
    freopen("s2.in", "r", stdin); freopen("s2.out", "w", stdout);
    getline(cin, pt);
    getline(cin, ct);
    getline(cin, s);
    fill(hehe, hehe + MAXN, '.');
    for (int i = 0; i < ct.size(); i ++) {
        hehe[ct[i]] = pt[i];
    }
    for (int i = 0; i < s.size(); i ++) {
        cout << char(hehe[s[i]]);
    }
    cout << endl;
    return 0;
}
 
/*
    
*/