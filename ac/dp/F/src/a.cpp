#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

const int MAX_N = 3001;

std::string s, t;

int memo[MAX_N][MAX_N];

std::string get_lcs() {
  s = " " + s;
  t = " " + t;
  int S = s.length(), T = t.length();

  for (int i = 0; i < S; i++) {
    for (int j = 0; j < T; j++) {
      memo[i][j] = 0;
    }
  }

  for (int i = 1; i < S; i++) {
    for (int j = 1; j < T; j++) {
      memo[i][j] = std::max(memo[i - 1][j], memo[i][j - 1]);

      if (s[i] == t[j]) {
        memo[i][j] = std::max(memo[i][j], memo[i - 1][j - 1] + 1);
      }
    }
  }

  std::string lcs = "";
  for (int i = S - 1, j = T - 1; i > 0 && j > 0;) {
    if (memo[i][j] == memo[i - 1][j]) {
      i--;
      continue;
    }

    if (memo[i][j] == memo[i][j - 1]) {
      j--;
      continue;
    }

    lcs += s[i];
    i--;
    j--;
  }

  for (int l = 0, r = lcs.length() - 1; l < r; l++, r--) {
    std::swap(lcs[l], lcs[r]);
  }

  return lcs;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> s >> t;

  std::cout << get_lcs() << '\n';

  return 0;
}
