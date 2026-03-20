#include <iostream>
#include <stack>

const int MAX_N = 1000001;

int N;
int array[MAX_N];

void compute_nge() {
  std::stack<int> stack;

  for (int i = N - 1; i >= 0; i--) {
    while (!stack.empty() && stack.top() <= array[i]) {
      stack.pop();
    }

    int current = array[i];

    if (stack.empty()) {
      array[i] = -1;
    } else {
      array[i] = stack.top();
    }

    stack.push(current);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> array[i];
  }

  compute_nge();

  for (int i = 0; i < N; i++) {
    std::cout << array[i] << ' ';
  }

  return 0;
}
