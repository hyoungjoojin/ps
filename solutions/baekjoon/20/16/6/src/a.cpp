#include <iostream>
#include <string>
#include <unordered_map>

const int MAX_N = 11;
const int MAX_M = 11;

int d[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
               {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n;
int m;
char grid[MAX_N][MAX_M];

std::unordered_map<std::string, long long> memo[MAX_N][MAX_M];

long long _find_recursive(std::string &s, int r, int c) {
  if (memo[r][c].find(s) != memo[r][c].end()) {
    return memo[r][c][s];
  }

  if (s.size() == 1) {
    return (memo[r][c][s] = (grid[r][c] == s[0] ? 1 : 0));
  }

  long long count = 0;

  if (grid[r][c] == s[0]) {
    std::string next_str = s.substr(1);
    for (int di = 0; di < 8; di++) {
      int next_r = (r + d[di][0] + n) % n, next_c = (c + d[di][1] + m) % m;
      count += _find_recursive(next_str, next_r, next_c);
    }
  }

  return memo[r][c][s] = count;
}

long long find(std::string &s) {
  long long count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      count += _find_recursive(s, i, j);
    }
  }

  return count;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int k;

  std::cin >> n >> m >> k;

  std::string line;

  for (int i = 0; i < n; i++) {
    std::cin >> line;

    for (int j = 0; j < m; j++) {
      grid[i][j] = line[j];
    }
  }

  std::string word;
  while (k--) {
    std::cin >> word;
    std::cout << find(word) << '\n';
  }

  return 0;
}
