#include <iostream>
#include <stack>
#include <string>

std::stack<char> stack;

bool is_vps(std::string &str) {
  bool valid = true;

  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(') {
      stack.push('(');
    } else if (!stack.empty()) {
      stack.pop();
    } else {
      valid = false;
      break;
    }
  }

  if (!stack.empty()) {
    valid = false;

    while (!stack.empty()) {
      stack.pop();
    }
  }

  return valid;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;

  std::string line;
  for (int t = 1; t <= T; t++) {
    std::cin >> line;
    std::cout << (is_vps(line) ? "YES\n" : "NO\n");
  }

  return 0;
}
