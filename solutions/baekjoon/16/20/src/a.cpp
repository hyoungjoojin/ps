#include <iostream>
#include <string>
#include <unordered_map>

const int MAX_N = 100001;

std::string names[MAX_N];
std::unordered_map<std::string, int> name_map;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N, M;
  std::cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    std::cin >> names[i];
    name_map[names[i]] = i;
  }

  std::string input;
  for (int i = 1; i <= M; i++) {
    std::cin >> input;

    char first_char = input[0];
    if ('0' <= first_char && first_char <= '9') {
      int index = std::stoi(input);
      std::cout << names[index] << "\n";
    } else {
      std::cout << name_map[input] << "\n";
    }
  }

  return 0;
}
