//stopped thinking at 01:25:43; not worth it; stupid ugly ass problem
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
string s;
string mth[12] = {"January ", "February ", "March ", "April ", "May ", "June ", "July ", "August ", "September ", "October ", "November ", "December "};
vector <int> v;

int toInt(int ind) {
    int hehe = (s[ind] - '0') * 10 + s[ind + 1] - '0';
    return hehe;
}

bool isInt(char c) {
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

int num(int ind) {
    if (ind + 7 >= s.size()) return -1;
    if (!(s[ind + 2] == s[ind + 5] && (s[ind + 2] == '.' || s[ind + 2] == '/')))
        return -1;
    if (!(isInt(ind) && isInt(ind + 1) && isInt(ind + 3) && isInt(ind + 4) && isInt(ind + 6) && isInt(ind + 7)))
        return -1;
    if (toInt(ind))
    if (ind + 8 < s.size() && ((s[ind + 8] >= 'a' && s[ind + 8] <= 'z') || (s[ind + 8] >= 'A' && s[ind + 8] <= 'Z') || isInt(s[ind + 8])))
        return -1;
    return ind + 6;
}

int month(int ind) {
    string word = "";
    for (int i = ind; i < s.size(); i++) {
        word += s[i];
        if (s[i] == ' ') break;
    }
    bool b = false;
    for (int i = 0; i < 12; i ++) {
        if (word == mth[i]) {
            ind += mth[i].size();
            b = true;
            break;
        }
    }
    if (!b) return -1;
    if (ind + 6 >= s.size()) return -1;
    if (!(isInt(s[ind]) && isInt(s[ind + 1])))
        return -1;
    ind += 2;
    if (!(s[ind] == ',' && s[ind + 1] == ' '))
        return -1;
    ind += 2;
    if (!(isInt(s[ind]) && isInt(s[ind + 1]) && s[ind + 2] == ','))
        return -1;
    return ind;
}
 
int32_t main() {
    freopen("y2k.in", "r", stdin); freopen("y2k.out", "w", stdout);
    cin >> n;
    while (n--) {
        getline(cin, s);
        v.clear();
        for (int i = 0; i < s.size(); i ++) {
            int x, y;
            x = num(i), y = month(i);
            if (isInt(s[i]) && x != -1) {
                v.pb(x);
            }
            if (y != -1) {
                v.pb(y);
            }
        }
        int ind = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (i != v[ind]) {
                cout << s[i];
                continue;
            }
            int hehe = (s[v[ind]] - '0') * 10 + s[v[ind] + 1] - '0';
            if (hehe > 24)
                cout << 1900 + hehe;
            else
                cout << 2000 + hehe;
            i++;
        }
        cout << '\n';
    }
    return 0;
}
 
/*
    
*/