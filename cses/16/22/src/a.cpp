#include <iostream>
#include <string>

const int N = 'z' - 'a' + 1;

int frequency[N];

int factorial(int n) {
  int result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }

  return result;
}

int get_count() {
  int total_count = 0;
  for (int i = 0; i < N; i++) {
    total_count += frequency[i];
  }

  int result = factorial(total_count);
  for (int i = 0; i < N; i++) {
    result /= factorial(frequency[i]);
  }

  return result;
}

std::string output = "";

void print(int remaining) {
  if (remaining == 0) {
    std::cout << output << '\n';
  }

  for (int i = 0; i < N; i++) {
    if (frequency[i] == 0) {
      continue;
    }

    frequency[i]--;
    output.push_back('a' + i);

    print(remaining - 1);

    frequency[i]++;
    output.pop_back();
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::string input;
  std::cin >> input;

  for (char ch : input) {
    frequency[ch - 'a']++;
  }

  std::cout << get_count() << '\n';

  print(input.length());

  return 0;
}
