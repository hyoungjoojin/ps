#include <iostream>
#include <vector>

const int MAX_N = 101;
const int MAX_K = 1e5 + 1;

int N;
int coins[MAX_N];

bool memo[MAX_K], temp[MAX_K];

std::vector<int> get_possible_sums() {
  memo[coins[0]] = true;

  for (int i = 1; i < N; i++) {
    for (int k = 1; k < MAX_K; k++) {
      temp[k] = memo[k] || (k >= coins[i] && memo[k - coins[i]]);
    }

    temp[coins[i]] = true;

    for (int k = 0; k < MAX_K; k++) {
      memo[k] = temp[k];
      temp[k] = false;
    }
  }

  std::vector<int> result;
  for (int k = 1; k < MAX_K; k++) {
    if (memo[k]) {
      result.push_back(k);
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> coins[i];
  }

  std::vector<int> result = get_possible_sums();

  std::cout << result.size() << '\n';
  for (int &i : result) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  return 0;
}
