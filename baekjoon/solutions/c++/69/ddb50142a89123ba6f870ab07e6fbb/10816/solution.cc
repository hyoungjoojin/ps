#include <iostream>
#include <unordered_map>

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num_cards = 0, num_queries = 0, number = 0;

  std::unordered_map<int, unsigned int> hash_table;

  std::cin >> num_cards;
  while (num_cards--) {
    std::cin >> number;

    if (hash_table.find(number) == hash_table.end())
      hash_table[number] = 1;
    else
      hash_table[number]++;
  }

  std::cin >> num_queries;
  while (num_queries--) {
    std::cin >> number;

    if (hash_table.find(number) == hash_table.end())
      std::cout << "0 ";
    else
      std::cout << hash_table[number] << ' ';
  }

  return 0;
}
