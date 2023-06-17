//02:10:30
//i think sample last case is wrong (5 straight 4 right, not 4 straight 5 left)
//update: test output in the solutions is also wrong
//update2: misunderstood question; get it "back" with minimum steps
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
 
int q, dis[5];
 
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("rover.in", "r", stdin); freopen("rover.out", "w", stdout);
    cin >> q;
    while (q--) {
        int num = -1;
        int dir = 0;
        fill(dis, dis + 5, 0);
        while (num != 0) {
            cin >> num;
            if (num == 1) {
                cin >> num;
                dis[dir] += num;
            }
            else if (num == 2) {
                dir = (dir + 1) % 4;
            }
            else if (num == 3) {
                dir = (dir - 1) + ((dir == 0)? 4 : 0);
            }
        }
        if (dis[0] > dis[2])
            dis[0] -= dis[2], dis[2] = 0;
        else
            dis[2] -= dis[0], dis[0] = 0;
        if (dis[1] > dis[3])
            dis[1] -= dis[3], dis[3] = 0;
        else
            dis[3] -= dis[1], dis[1] = 0;
        int disTot = dis[0] + dis[1] + dis[2] + dis[3];
        cout << "Distance is " << disTot << '\n';
        if (dir == 0) {
            swap(dis[0], dis[2]);
            swap(dis[1], dis[3]);
        }
        else if (dir == 1) {
            swap(dis[0], dis[1]);
            swap(dis[2], dis[3]);
            swap(dis[1], dis[3]);
        }
        else if (dir == 3) {
            swap(dis[2], dis[3]);
            swap(dis[1], dis[2]);
            swap(dis[0], dis[1]);
        }
        if (dis[0]) {
            cout << "1\n" << dis[0] << '\n';
        }
        if (dis[1]) {
            cout << "2\n1\n" << dis[1] << '\n';
        }
        else if (dis[3]) {
            cout << "3\n1\n" << dis[3] << '\n';
        }
        if (dis[2]) {
            if (dis[1]) {
                cout << "d2\n1\n" << dis[2] << '\n';
            }
            else if (dis[3]) {
                cout << "d3\n1\n" << dis[2] << '\n';
            }
            else {
                cout << "d2\n2\n1\n" << dis[2] << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}
 
/*
    
*/