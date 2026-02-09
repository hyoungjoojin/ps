#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string solution(std::string &input, int k) {
  if (k > input.size() || k <= 0) {
    return "none";
  }

  std::vector<std::string> suffixes;

  std::string suffix = "";
  for (int i = 0; i < input.size(); i++) {
    suffix = input[input.size() - i - 1] + suffix;
    suffixes.push_back(suffix);
  }

  std::sort(suffixes.begin(), suffixes.end());
  return suffixes[k - 1];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  int k;
  std::string input;

  for (int t = 1; t <= T; t++) {
    std::cin >> k >> input;
    std::cout << '#' << t << ' ' << solution(input, k) << '\n';
  }

  return 0;
}
