#include <iostream>
#include <string>

int N;
std::string S;

std::string solution() {
  std::string result = "";
  bool started = false;

  for (int i = 0; i < N; i++) {
    if (!started && S[i] == 'o') {
      continue;
    }

    started = true;
    result += S[i];
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> S;

  std::cout << solution() << '\n';

  return 0;
}
