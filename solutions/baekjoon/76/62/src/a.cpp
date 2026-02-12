#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

int total_count;
std::unordered_map<int, int> count_map;
std::priority_queue<int> max_heap;
std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

void init() {
  total_count = 0;
  count_map.clear();

  while (!max_heap.empty()) {
    max_heap.pop();
  }

  while (!min_heap.empty()) {
    min_heap.pop();
  }
}

void insert(int x) {
  total_count++;
  count_map[x]++;
  max_heap.push(x);
  min_heap.push(x);
}

void remove_max() {
  while (!max_heap.empty()) {
    int top = max_heap.top();
    max_heap.pop();

    if (count_map[top] != 0) {
      total_count--;
      count_map[top]--;
      break;
    }
  }
}

void remove_min() {
  while (!min_heap.empty()) {
    int top = min_heap.top();
    min_heap.pop();

    if (count_map[top] != 0) {
      total_count--;
      count_map[top]--;
      break;
    }
  }
}

bool is_empty() { return total_count == 0; }

int get_max() {
  while (!max_heap.empty()) {
    int top = max_heap.top();

    if (count_map[top] != 0) {
      return top;
    } else {
      max_heap.pop();
    }
  }

  return 0;
}

int get_min() {
  while (!min_heap.empty()) {
    int top = min_heap.top();

    if (count_map[top] != 0) {
      return top;
    } else {
      min_heap.pop();
    }
  }

  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t = 0;
  std::cin >> t;

  int num_operations;
  while (t--) {
    init();

    std::cin >> num_operations;

    char command;
    int x;

    while (num_operations--) {
      std::cin >> command >> x;

      if (command == 'I') {
        insert(x);
      } else {
        if (x == 1) {
          remove_max();
        } else {
          remove_min();
        }
      }
    }

    if (is_empty()) {
      std::cout << "EMPTY\n";
    } else {
      std::cout << get_max() << ' ' << get_min() << '\n';
    }
  }

  return 0;
}
