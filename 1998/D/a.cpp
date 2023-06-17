//01:32:25
//fixed multiplication part; solved;
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
vector <string> a, b;
 
int32_t main() {
    freopen("lottery.in", "r", stdin); freopen("lottery.out", "w", stdout);
    cin >> q;
    string x;
    getline(cin, x);
    while (q--) {
        getline(cin, x);
        string s = "";
        a.clear(); b.clear();
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == ' ') {
                a.pb(s);
                s = "";
            }
            else {
                s += x[i];
            }
        }
        a.pb(s);
        for (int i = 1; i < a.size(); i++) {
            if (a[i] == "X") {
                a[i + 1] = "(" + a[i - 1] + " X " + a[i + 1] + ")";
                a[i] = a[i - 1] = ""; 
                i ++;
            }
            // else if (i == a.size() - 1 || (i < a.size() - 1 && a[i + 1] != "X")) {
            //     b.pb(a[i]);
            // }
        }
        for (int i = 0; i < a.size(); i++) {
            // cout << b[i] << " ";
            if (a[i] != "")
                b.pb(a[i]);
        }
        cout << '\n';
        for (int i = 0; i < b.size(); i ++) {
            if ((b[i] == "+" || b[i] == "-") && i != b.size() - 2) {
                b[i + 1] = "(" + b[i - 1] + " " + b[i] + " " + b[i + 1] + ")";
                b[i] = b[i - 1] = "";
                i++;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i] != "")
                cout << b[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}
 
/*
    
*/