#include <iostream>
#include <string>

const int MAX_LINES = 6562;

std::string lines[MAX_LINES];

void _get_pattern_recursive(int n, int start, int end) {
  if (n == 3) {
    lines[start] += "***";
    lines[start + 1] += "* *";
    lines[start + 2] += "***";
    return;
  }

  int next_n = n / 3;

  std::string spaces = "";
  for (int i = 0; i < next_n; i++) {
    spaces += ' ';
  }

  for (int i = 0; i < 3; i++) {
    _get_pattern_recursive(next_n, start, start + next_n - 1);
  }

  start += next_n;
  _get_pattern_recursive(next_n, start, start + next_n - 1);
  for (int i = start; i < start + next_n; i++) {
    lines[i] += spaces;
  }
  _get_pattern_recursive(next_n, start, start + next_n - 1);

  start += next_n;
  for (int i = 0; i < 3; i++) {
    _get_pattern_recursive(next_n, start, start + next_n - 1);
  }
}

void get_pattern(int n) { _get_pattern_recursive(n, 0, n - 1); }

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  get_pattern(n);

  for (int i = 0; i < n; i++) {
    std::cout << lines[i] << '\n';
  }

  return 0;
}
