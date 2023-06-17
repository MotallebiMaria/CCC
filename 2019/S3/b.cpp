#include <bits/stdc++.h>

using namespace std;

const int N = 3;
int grid[N][N];
bool used[N][N];

bool check(int a, int b, int c) {
  return (b - a == c - b);
}

bool check_grid() {
  // check rows
  for (int i = 0; i < N; i++) {
    int a = grid[i][0];
    int b = grid[i][1];
    int c = grid[i][2];
    if (used[i][0] && used[i][1] && used[i][2] && !check(a, b, c)) {
      return false;
    }
  }
  // check columns
  for (int j = 0; j < N; j++) {
    int a = grid[0][j];
    int b = grid[1][j];
    int c = grid[2][j];
    if (used[0][j] && used[1][j] && used[2][j] && !check(a, b, c)) {
      return false;
    }
  }
  return true;
}

bool solve(int pos) {
  if (pos == N * N) {
    return check_grid();
  }

  int i = pos / N;
  int j = pos % N;

  if (used[i][j]) {
    return solve(pos + 1);
  }

  for (int val = -1000000; val <= 1000000; val++) {
    grid[i][j] = val;
    if (solve(pos + 1)) {
      return true;
    }
  }
  return false;
}

int main() {
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < N; j++) {
      char c = s[j * 2];
      if (c == 'X') {
        used[i][j] = false;
      } else {
        used[i][j] = true;
        grid[i][j] = stoi(&c);
      }
    }
  }

  if (solve(0)) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << grid[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "No solution found." << endl;
  }

  return 0;
}
