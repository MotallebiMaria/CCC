//00:03:51; done
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
pair <int, string> p[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int ind = -1;
    do {
        ind ++;
        cin >> p[ind].second >> p[ind].first;
    } while (p[ind].second != "Waterloo");
    sort(p, p + ind);
    cout << p[0].second << endl;
    return 0;
}
 
/*
    
*/