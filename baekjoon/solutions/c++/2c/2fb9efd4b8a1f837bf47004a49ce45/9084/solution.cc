// 12 ms, 2924 KB

#include <algorithm>
#include <iostream>
#include <vector>

int get_num_combinations(const std::vector<int> &, int);

int main(int argc, const char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int num_testcases = 0;
  std::cin >> num_testcases;

  int num_coins = 0, price = 0;
  while (num_testcases--) {
    std::cin >> num_coins;
    std::vector<int> coins(num_coins);

    for (int &coin : coins)
      std::cin >> coin;
    std::reverse(coins.begin(), coins.end());

    std::cin >> price;
    std::cout << get_num_combinations(coins, price) << '\n';
  }

  return 0;
}

int get_num_combinations_recursive(const std::vector<int> &coins, int price,
                                   int index,
                                   std::vector<std::vector<int>> &memo) {
  if (index == coins.size() - 1)
    return (price % coins[index] == 0 ? 1 : 0);

  if (memo[index][price] != -1)
    return memo[index][price];

  int num_combinations = 0;
  for (int i = 0; i <= price; i += coins[index]) {
    num_combinations +=
        get_num_combinations_recursive(coins, price - i, index + 1, memo);
  }

  memo[index][price] = num_combinations;
  return num_combinations;
}

int get_num_combinations(const std::vector<int> &coins, int price) {
  std::vector<std::vector<int>> memo(coins.size() - 1,
                                     std::vector<int>(price + 1, -1));

  return get_num_combinations_recursive(coins, price, 0, memo);
}
