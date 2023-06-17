//01:24:33
//commented mistake; understood official solution
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
 
int q;
int val[20] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000}; //IVXLCDM

int toDec(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'I') {
            if (i < s.size() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                num --;
            else num ++;
        }
        else if (s[i] == 'V') num += 5;
        else if (s[i] == 'X') {
            if (i < s.size() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                num -= 10;
            else num += 10;
        }
        else if (s[i] == 'L') num += 50;
        else if (s[i] == 'C') {
            if (i < s.size() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                num -= 100;
            else num += 100;
        } //1: forgot to add value for D; added below
        else if (s[i] == 'D') num += 500;
        else num += 1000;
    }
    return num;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("rom.in", "r", stdin); freopen("rom.out", "w", stdout);
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        string a, b;
        bool plus = false;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '+') plus = true;
            else if (plus) b += s[i];
            else a += s[i];
        }
        int x, y;
        x = toDec(a); y = toDec(b);
        // cout << x << " " << y << '\n';
        cout << s;
        int rem = x + y;
        if (rem > 1000) {
            cout << "CONCORDIA CUM VERITATE\n";
            continue;
        }
        int ind, I, V, X, L, C, D, M;
        ind = 12, V = X = L = C = 0;
        string ans = "";
        while (rem) {
            while (val[ind] > rem) ind--;
            int n = val[ind];
            if (n == 1000) {
                ans += "M";
                rem -= 1000;
            }
            else if (n == 900) {
                ans += "CM";
                rem -= 900;
            }
            else if (n == 500) {
                ans += "D";
                rem -= 500;
            }
            else if (n == 400) {
                ans += "CD";
                rem -= 400;
            }
            else if (n == 100) {
                if (C == 3) {
                    ans += "XC";
                    rem -= 90;
                    C = 1;
                }
                else {
                    ans += "C";
                    rem -= 100;
                    C ++;
                }
            }
            else if (n == 90) {
                ans += "XC";
                rem -= 90;
            }
            else if (n == 50) {
                if (L == 3) {
                    ans += "XL";
                    rem -= 40;
                    L = 1;
                }
                else {
                    ans += "L";
                    rem -= 50;
                    L ++;
                }
            }
            else if (n == 40) {
                ans += "XL";
                rem -= 40;
            }
            else if (n == 10) {
                if (X == 3) {
                    ans += "IX";
                    rem -= 9;
                    X = 1;
                }
                else {
                    ans += "X";
                    rem -= 10;
                    X ++;
                }
            }
            else if (n == 9) {
                ans += "IX";
                rem -= 9;
            }
            else if (n == 5) {
                if (V == 3) {
                    ans += "IV";
                    rem -= 4;
                    V = 1;
                }
                else {
                    ans += "V";
                    rem -= 5;
                    V ++;
                }
            }
            else if (n == 4) {
                ans += "IV";
                rem -= 4;
            }
            else {
                ans += "I";
                rem --;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
 
/*
    
*/