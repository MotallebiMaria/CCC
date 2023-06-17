//00:16:24
//done
//tc2
//mistake1: didn't consider words individually
//mistake1 fixed in -00:05:26
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
 
int n;
string s[5], r[5];

string toLower(string x) {
    for (int i = 0; i < x.size(); i ++) {
        if (x[i] < 'a' && x[i] != ' ')
            x[i] += 'a' - 'A';
    }
    return x;
}

string rhm(string x) {
    int ind = 0;
    for (int i = 0; i < x.size(); i ++) {
        if (x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u')
            ind = i;
    }
    string out = "";
    for (int i = ind; i < x.size(); i ++) {
        out += x[i];
    }
    return out;
}

string last(string x) {
    int ind = 0;
    for (int i = 0; i < x.size(); i ++) {
        if (x[i] == ' ') ind = i + 1;
    }
    string out = "";
    for (int i = ind; i < x.size(); i ++) {
        out += x[i];
    }
    return out;
}
 
int32_t main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("poetry.in", "r", stdin); freopen("poetry.out", "w", stdout);
    cin >> n;
    getline(cin, s[0]);
    while (n--) {
        for (int i = 0; i < 4; i ++) {
            getline(cin, s[i]);
            s[i] = last(s[i]);
            s[i] = toLower(s[i]);
            r[i] = rhm(s[i]);
            // cout << s[i] << " " << r[i] << '\n';
        }
         if (r[0] == r[1] && r[1] == r[2] && r[2] == r[3])
            cout << "perfect" << endl;
        else if (r[0] == r[1] && r[2] == r[3])
            cout << "even" << endl;
        else if (r[0] == r[2] && r[1] == r[3])
            cout << "cross" << endl;
        else if (r[0] == r[3] && r[1] == r[2])
            cout << "shell" << endl;
        else
            cout << "free" << endl;
    }
    return 0;
}
 
/*
2
I say to you boo
You say boohoo
I cry too
It is too much foo
Your teacher has to mark
and mark and mark and teach
To do well on this contest you have to reach
tor everything with a lark
*/