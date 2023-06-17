//01:27:11; done
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

const int MAXN = 5e1 + 10;
int a, b, dfs[MAXN];
bool war[MAXN][MAXN], mark[MAXN], friends[MAXN][MAXN];
vector <int> v[MAXN];

void befriend(int x, int y) {
    for (int i = 1; i < MAXN; i ++) {
        if (war[i][x] || war[i][y]) {
            war[i][x] = war[x][i] = war[i][y] = war[y][i] = true;
        } 
    }
    return;
}

void warshall() {
    for (int i = 1; i < 19; i ++) {
        fill(war[i], war[i] + MAXN, false);
        war[i][i] = true;
    }
    for (int i = 1; i < 19; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            war[i][v[i][j]] = war[v[i][j]][i] = true;
            befriend(i, v[i][j]);
        }
    }
    return;
}

void unfriend(int x, int y) {
    vector <int> ppl;
    for (int i = 0; i < v[x].size(); i ++) {
        if (v[x][i] != y) ppl.pb(v[x][i]);
    }
    v[x] = ppl;
    ppl.clear();
    for (int i = 0; i < v[y].size(); i ++) {
        if (v[y][i] != x) ppl.pb(v[y][i]);
    }
    v[y] = ppl;
    friends[x][y] = friends[y][x] = false;
    return;
}

ll dos(int x, int y) {
    fill(mark, mark + MAXN, false);
    fill(dfs, dfs + MAXN, 0);
    mark[x] = true;
    vector <int> ppl, pplp;
    ppl.pb(x);
    while (ppl.size()) {
        pplp.clear();
        for (int i = 0; i < ppl.size(); i ++) {
            for (int j = 0; j < v[ppl[i]].size(); j ++) {
                if (!mark[v[ppl[i]][j]]) {
                    pplp.pb(v[ppl[i]][j]);
                    mark[v[ppl[i]][j]] = true;
                    dfs[v[ppl[i]][j]] = dfs[ppl[i]] + 1;
                }
            }
        }
        ppl = pplp;
    }
    return dfs[y];
}
 
int32_t main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    v[1].pb(6);
    v[2].pb(6);
    v[3].pb(4); v[3].pb(5); v[3].pb(6); v[3].pb(15); 
    v[4].pb(3); v[4].pb(5); v[4].pb(6); 
    v[5].pb(3); v[5].pb(4); v[5].pb(6); 
    v[6].pb(1); v[6].pb(2); v[6].pb(3); v[6].pb(4); v[6].pb(5); v[6].pb(7); 
    v[7].pb(6); v[7].pb(8); 
    v[8].pb(7); v[8].pb(9); 
    v[9].pb(8); v[9].pb(10); v[9].pb(12); 
    v[10].pb(9); v[10].pb(11);
    v[11].pb(10); v[11].pb(12);
    v[12].pb(9); v[12].pb(11); v[12].pb(13);
    v[13].pb(12); v[13].pb(14); v[13].pb(15);
    v[14].pb(13);
    v[15].pb(3); v[15].pb(13);
    v[16].pb(17); v[16].pb(18);
    v[17].pb(16); v[17].pb(18);
    v[18].pb(16); v[18].pb(17);
    warshall();
    for (int i = 1; i < 19; i ++) {
        for (int j = 0; j < v[i].size(); j ++) {
            friends[i][v[i][j]] = friends[v[i][j]][i] = true;
        }
    }
    char c;
    cin >> c;
    while (c != 'q') {
        if (c == 'i') { // befriend a & b
            cin >> a >> b;
            if (friends[a][b]) continue;
            v[a].pb(b); v[b].pb(a);
            friends[a][b] = friends[b][a] = war[a][b] = war[b][a] = true;
            befriend(a, b);
        }
        else if (c == 'd') { // unfriend a & b
            cin >> a >> b;
            unfriend(a, b);
            warshall();
        }
        else if (c == 'n') { // # of friends
            cin >> a;
            cout << v[a].size() << endl;
        }
        else if (c == 'f') { // # of friends of friends
            cin >> a;
            int cnt = 0;
            fill(mark, mark + MAXN, false);
            mark[a] = true;
            for (int i = 0; i < v[a].size(); i ++) {
                for (int j = 0; j < v[v[a][i]].size(); j ++) {
                    if (!mark[v[v[a][i]][j]] && !friends[a][v[v[a][i]][j]]) {
                        mark[v[v[a][i]][j]] = true;
                        cnt ++;
                    }
                }
            }
            cout << cnt << endl;
        }
        else if (c == 's') { // degree of separation
            cin >> a >> b;
            if (!war[a][b])
                cout << "Not connected.";
            else
                cout << dos(a, b);
            cout << endl;
        }
        cin >> c;
    }
    return 0;
}
 
/*
    rm friend: v = vp, rm connections???
*/