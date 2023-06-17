//00:18:00
//done
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
 
int pt[10];
string hand;
vector <char> v[10];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> hand;
    int ind = 0;
    for (int i = 0; i < hand.size(); i ++) {
        char c = hand[i];
        if (c == 'C') ind = 0;
        else if (c == 'D') ind = 1;
        else if (c == 'H') ind = 2;
        else if (c == 'S') ind = 3;
        else {
            v[ind].pb(c);
            int num = 0;
            if (c == 'A') num = 4;
            else if (c == 'K') num = 3;
            else if (c == 'Q') num = 2;
            else if (c == 'J') num = 1;
            pt[ind] += num;
        }
    }
    cout << "Cards Dealt              Points\n";
    int spc[4] = {6, 9, 7, 7};
    int sum = 0;
    for (int i = 0; i < 4; i ++) {
        if (i == 0) cout << "Clubs ";
        else if (i == 1) cout << "Diamonds ";
        else if (i == 2) cout << "Hearts ";
        else cout << "Spades ";
        for (int j = 0; j < v[i].size(); j ++) {
            cout << v[i][j] << " ";
            spc[i] += 2;
        }
        if (!v[i].size()) pt[i] += 3;
        else if (v[i].size() == 1) pt[i] += 2;
        else if (v[i].size() == 2) pt[i] ++;
        if (pt[i] > 9) spc[i] ++;
        for (int j = 0; j < 29 - spc[i]; j ++) {
            cout << " ";
        }
        cout << pt[i] << '\n';
        sum += pt[i];
    }
    cout << "                      Total ";
    if (sum < 9) cout << " ";
    cout << sum << endl;
    return 0;
}
 
/*
    
*/