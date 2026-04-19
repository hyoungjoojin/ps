#include <iostream>

int A;
int B;

int solution() {
  int ab = 1, ba = 1;

  for (int i = 0; i < B; i++) {
    ab *= A;
  }

  for (int i = 0; i < A; i++) {
    ba *= B;
  }

  return ab + ba;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> A >> B;

  std::cout << solution() << '\n';

  return 0;
}
