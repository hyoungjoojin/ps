#include <algorithm>
#include <iostream>
#include <string>

const int MAX_LENGTH = 1001;

int length = 0;
std::string text;

int suffix_array[MAX_LENGTH];

bool cmp(int a, int b) { return text.substr(a) < text.substr(b); }

void construct_suffix_array() {
  for (int i = 0; i < length; i++) {
    suffix_array[i] = i;
  }

  std::sort(suffix_array, suffix_array + length, cmp);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> text;
  length = text.size();

  construct_suffix_array();

  for (int i = 0; i < length; i++) {
    for (int c = suffix_array[i]; c < length; c++) {
      std::cout << text[c];
    }
    std::cout << '\n';
  }

  return 0;
}
