//00:05:02; done; 6/15
//00:04:08; 
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

const int MAXN = 3e1 + 10;
int n;
string ln1[MAXN], ln2[MAXN];
map <string, string> m1, m2;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> ln1[i];
    for (int i = 0; i < n; i ++) cin>> ln2[i];
    for (int i= 0; i < n; i ++) {
        m1[ln1[i]] = ln2[i];
        m2[ln2[i]] = ln1[i];
    }
    for (int i = 0; i < n; i ++) {
        if (m1[ln1[i]] != m2[ln1[i]] || m1[ln1[i]] == ln1[i]) {
            cout << "bad" << endl;
            return 0;
        }
    }
    cout << "good" << endl;
    return 0;
}
 
/*
    
*/