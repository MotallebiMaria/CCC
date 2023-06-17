//01:32:08
//doesn't give "can/can't surf" output
//fixed for tc 1 after 10 mins for no reason
//tc2 segmentation fault for "can/can't"
//2 * 36 + 9 mins
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
int n, acs[MAXN][MAXN];
string s, hehe = "<A HREF=";
map <string, vector <string>> m;
vector <string> v;
map <string, int> num;

vector <string> findHehe(string x) {
    vector <string> out;
    bool b = false;
    for (int i = 0; i < x.size(); i ++) {
        if (b) {
            if (x[i] == '\"') {
                b = false;
                continue;
            }
            out.back() += x[i];
        }
        if (i + 8 < x.size() && x[i] == '<' && x[i + 1] == 'A' && x[i + 2] == ' ' && x[i + 3] == 'H' && x[i + 4] == 'R' && x[i + 5] == 'E' && x[i + 6] == 'F' && x[i + 7] == '=' && x[i + 8] == '\"') {
            i += 8;
            out.pb("");
            b = true;
        }
    }
    return out;
}

void rmspc(string x) {
    if (x.back() == ' ') {
        x.erase(x.begin() + x.size() - 1);
    }
}
 
int32_t main() {
    freopen("surf.in", "r", stdin); freopen("surf.out", "w", stdout);
    cin >> n;
    getline(cin, s);
    while (n--) {
        string url;
        getline(cin, url);
        rmspc(url);
        num[url] = v.size();
        v.pb(url);
        s = "";
        while (s != "</HTML>") {
            getline(cin, s);
            rmspc(s);
            vector <string> fh;
            fh = findHehe(s);
            for (int i = 0; i < fh.size(); i ++) {
                m[url].pb(fh[i]);
                cout << "Link from " << url << " to " << fh[i] << '\n';
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        acs[num[v[i]]][num[v[i]]] = true;
        for (int j = 0; j < m[v[i]].size(); j ++) {
            acs[num[v[i]]][num[m[v[i]][j]]] = true;
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (acs[i][j]) {
                for (int k = 0; k < n; k ++) {
                    if (acs[j][k]) {
                        acs[i][k] = true;
                    }
                }
            }
        }
    }
    s = "";
    cout << '\n';
    while (s != "The End") {
        getline(cin, s);
        rmspc(s);
        if (s == "The End") break;
        string x;
        getline(cin, x);
        rmspc(x);
        if (acs[num[s]][num[x]]) {
            cout << "Can";
        }
        else {
            cout << "Can't";
        }
        cout << " surf from " << s << " to " << x << '\n';
    }
    return 0;
}
 
/*
    
*/