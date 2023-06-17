//00:57:57
//tc5 problem
//note: use array and shift every element to right or left
//used array; fixed for some reason
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
 
const int MAXN = 1e3 + 10;
int n;
double a[MAXN];
// vector <double> v;
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("brooks.in", "r", stdin); freopen("brooks.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        // int x;
        cin >> a[i];
        // v.pb(x);
    }
    int hehe = 0;
    while (hehe != 77) {
        // for (int i = 0; i < n; i ++) {
        //     cout << (int)a[i] << " ";
        // }
        // cout << '\n';
        cin >> hehe;
        if (hehe == 99) {
            double prc;
            int num;
            cin >> num >> prc;
            double right = a[num - 1] * ((double)100 - prc) / (double)100;
            a[num - 1] -= right;
            n ++;
            for (int i = n - 1; i > num; i --) {
                a[i] = a[i - 1];
            }
            a[num] = right;
        }
        else if (hehe == 88) {
            int num;
            cin >> num;
            // cout << "add " << v[num - 1] << " " << v[num] << '\n';
            a[num - 1] += a[num];
            n --;
            for (int i = num; i < n; i ++) {
                a[i] = a[i + 1];
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        cout << round(a[i]) << " ";
    }
    cout << endl;
    return 0;
}
 
/*
    
*/