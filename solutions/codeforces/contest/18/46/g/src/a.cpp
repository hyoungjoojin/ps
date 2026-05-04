#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int INF = std::numeric_limits<int>::max();

const int MAX_N = 1025;
const int MAX_M = 1e3 + 1;

int n;

int start;
int end = 0;

int num_medicines;
std::pair<int, std::pair<int, int>> medicines[MAX_M];

int encode(std::string &str) {
  int result = 0;
  for (char ch : str) {
    result <<= 1;
    if (ch == '1') {
      result++;
    }
  }

  return result;
}

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                    std::greater<>>
    pq;

int distance[MAX_N];

int find_minimum_days() {
  for (int i = 0; i <= (1 << n); i++) {
    distance[i] = INF;
  }

  distance[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [d_v, v] = pq.top();
    pq.pop();

    if (distance[v] < d_v) {
      continue;
    }

    for (int i = 0; i < num_medicines; i++) {
      int w_adj = medicines[i].first;
      auto &[remove, add] = medicines[i].second;

      int adj = v;
      adj &= remove;
      adj |= add;

      int d_adj = d_v + w_adj;

      if (distance[adj] > d_adj) {
        distance[adj] = d_adj;
        pq.push({d_adj, adj});
      }
    }
  }

  return distance[end] == INF ? -1 : distance[end];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  std::string input;
  while (t--) {
    std::cin >> n >> num_medicines;

    std::cin >> input;
    start = encode(input);

    for (int i = 0; i < num_medicines; i++) {
      std::cin >> medicines[i].first;

      std::cin >> input;
      int remove = encode(input);
      remove = ((1 << n) - 1) ^ remove;

      std::cin >> input;
      int add = encode(input);

      medicines[i].second = {remove, add};
    }

    std::cout << find_minimum_days() << '\n';
  }

  return 0;
}
