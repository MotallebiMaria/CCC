//01:23:11
//solved;
//notes: attention to format (missed "There are x rounds.")
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
bool b;

void game(int u, int o, int e, int round) {
    cout << "Round " << round << ": " << u << " undefeated, " << o << " one-loss, " << e << " eliminated\n";
    if (u == 0 && o == 1) {
        cout << "There are " << round << " rounds.\n";
        return;
    }
    if (u == 1 && o == 1) {
        game(0, 2, e, round + 1);
    }
    else {
        game(u / 2 + u % 2, o - o / 2 + u / 2, e + o / 2, round + 1);
    }
    // int U, O, E;
    // U = u / 2 + u % 2;
    // O = o + u / 2
    // E = e + o / 2;
    // if (round == 0)
    //     O = u / 2, E = 0;
    // else if (u == 1 && o == 1)
    //     U = 0, O = 2, E = e;
    // else if (u == 0 && o == 2)
    //     U = 0, O = 1;
    // game(U, O, E, round + 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("dkc.in", "r", stdin); freopen("dkc.out", "w", stdout);
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        int u, o, e;
        game(t, 0, 0, 0);
        cout << endl;
    }
    return 0;
}
 
/*
    b) ??
    c) 2t-1
*/