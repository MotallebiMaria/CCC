//-01:05:10
//solved;
//mistake: equalized A and B size before figuring out if A<B
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
vector <int> a, b, Ans;

void noLeading() {
    reverse(all(a));
    for (int i = a.size() - 1; i > 0; i --) {
        if (a[i]) break;
        a.pop_back();
    }
    reverse(all(a));
}

void sbt() {
    int num = a.size() - b.size();
    for (int i = a.size() - 1; i >= 0; i --) {
        if (i >= num)
            a[i] -= b[i - num];
        if (a[i] < 0)
            a[i] += 10, a[i - 1] --;
    }
    return;
}

bool aLessB() {
    noLeading();
    if (a.size() < b.size()) return true;
    if (a.size() > b.size()) return false;
    for (int i = 0; i < a.size(); i ++) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return false;
}

void hehe(int cnt) {
    // cout << cnt << endl;
    if (cnt == 0) return;
    Ans.pb(0);
    while (!aLessB()) {
        // for (int i = 0; i < a.size(); i ++) {
        //     cout << a[i];
        // }
        // cout << " - ";
        // for (int i = 0; i < b.size(); i ++) {
        //     cout << b[i];
        // }
        // cout << " = ";
        sbt();
        // for (int i = 0; i < a.size(); i ++) {
        //     cout << a[i];
        // }
        // cout << endl;
        // cout << "noLeading" << endl;
        Ans.back() ++;
    }
    b.pop_back();
    hehe(cnt - 1);
}

int32_t main() {
    freopen("div.in", "r", stdin); freopen("div.out", "w", stdout);
    cin >> q;
    while (q--) {
        string A, B;
        cin >> A >> B;
        a.clear(); b.clear(); Ans.clear();
        for (int i = 0; i < A.size(); i++) {
            a.pb(A[i] - '0');
        }
        for (int i = 0; i < B.size(); i ++) {
            b.pb(B[i] - '0');
        }
        // cout << a.size() << " " << b.size() << '\n';
        if (aLessB()) {
            cout << "0\n" << A << "\n\n";
            continue;
        }
        for (int i = B.size(); i < A.size(); i++) {
            b.pb(0);
        }
        hehe(A.size() - B.size() + 1);
        for (int i = 0; i < Ans.size(); i++) {
            cout << Ans[i];
        }
        cout << '\n';
        for (int i = 0; i < a.size(); i ++) {
            cout << a[i];
        }
        cout << "\n\n";
    }    
    return 0;
}
 
/*
    
*/