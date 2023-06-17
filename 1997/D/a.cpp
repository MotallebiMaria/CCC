//01:10:12
//understood question wrong; will have to do again
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

const int MAXN = 2e5 + 10;
int q;
map <string, int> m;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("ddc.in", "r", stdin); freopen("ddc.out", "w", stdout);
    cin >> q;
    while (q--) {
        string dct;
        string txt;
        getline(cin, dct);
        getline(cin, dct);
        getline(cin, txt);
        string word = "";
        int cnt = 0;
        for (int i = 0; i < dct.size(); i++) {
            if (dct[i] == ' ') {
                if (!m[word]) m[word] = ++cnt;
                word = "";
            }
            else {
                word += dct[i];
            }
        }
        m[word] = ++cnt;
        word = "";
        for (int i = 0; i < txt.size(); i++) {
            if (txt[i] == ' ') {
                if (m[word]) cout << m[word];
                else cout << word;
                cout << " ";
                word = "";
            }
            else {
                word += txt[i];
            }
        }
        if (m[word]) cout << m[word];
        else cout << word;
        cout << '\n';
    }
    return 0;
}
 
/*
    
*/
