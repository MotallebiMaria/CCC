//00:24:00
//00:10:11
//done
//tc3; mistake1: several winners in increasing player number order, not decreasing
//-00:01:00 mistake1 fixed
//tc5; mistake2: wr calculation same points have to be same rank
//-00:09:17 mistake2 fixed
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
 
const int MAXN = 1e2 + 10;
int n, k, wr[MAXN];
pair <int, int> yr[MAXN];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("yodeller.in", "r", stdin); freopen("yodeller.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n;  i ++ ) {
        yr[i].first = i;
    }
    while (k--) {
        for (int i = 0 ; i < n; i ++) {
            int x;
            cin >> x;
            swap(yr[i].first, yr[i].second);
            yr[i].first += x;
        }
        sort(yr, yr + n);
        reverse(yr, yr + n);
        int rank = 0;
        for (int i = 0; i < n; i ++) {
            if (i && yr[i].first != yr[i - 1].second) {
                // cout << "hehe " << i << ": " << yr[i].first << " " << yr[i - 1].first << '\n';;
                rank ++;
            }
            wr[yr[i].second] = max(wr[yr[i].second], rank);
            swap(yr[i].first, yr[i].second);
        }
        sort(yr, yr + n);
    }
    for (int i = 0; i < n; i ++) {
        swap(yr[i].first, yr[i].second);
    }
    sort(yr, yr + n);
    for (int i =0; i < n; i ++) {
        if (yr[i].first != yr[n - 1].first) continue;
        cout << "Yodeller " << yr[i].second + 1 << " is the TopYodeller: score " << yr[i].first << ", worst rank " << wr[yr[i].second] + 1<< '\n';
    }
    return 0;
}
 
/*
    
*/