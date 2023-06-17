//00:03:36; done
//accepted
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
 
int y;
bool mark[10];

bool distinct(int x) {
    fill(mark, mark + 10, false);
    while (x) {
        if (mark[x % 10]) return false;
        mark[x % 10] = true, x /= 10;
    }
    return true;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> y;
    y ++;
    while (!distinct(y)) y ++;
    cout << y << endl;
    return 0;
}
 
/*
    
*/