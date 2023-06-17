//
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

const int MAXN = 1e4 + 10;
int n;
char anskey[MAXN], stu[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> stu[i];
    for (int i = 0; i < n; i ++) cin >> anskey[i];
    int mark = 0;
    for (int i = 0; i < n; i ++) {
        if (stu[i] == anskey[i])
            mark ++;
    }
    cout << mark << endl;
    return 0;
}
 
/*
    
*/