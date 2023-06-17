//02:42:50
//solved;
//notes: turn sync on when getline; attention to output format (missed ".")
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
int q;
string s[MAXN], v[MAXN], o[MAXN];
 
int32_t main() {
    freopen("sent.in", "r", stdin); freopen("sent.out", "w", stdout);
    cin >> q;
    while (q--) {
        int S, V, O;
        cin >> S >> V >> O;
        getline(cin, s[0]);
        for (int i = 0; i < S; i++) {
            getline(cin, s[i]);
        }
        for (int i = 0; i < V; i++) {
            getline(cin, v[i]);
        }
        for (int i = 0; i < O; i++) {
            getline(cin, o[i]);
        }
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < V; j++) {
                for (int k = 0; k < O; k++) {
                    cout << s[i] << " " << v[j] << " " << o[k] << ".\n";
                }
            }
        }
        cout << '\n';
        
    }
    return 0;
}
 
/*
    
*/