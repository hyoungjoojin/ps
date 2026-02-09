#include <algorithm>
#include <iostream>

int num_elements;
int num_groups;

int elements[200001];
int groups[200001];

int solution() {
  int max = 0;
  for (int i = 0; i < num_elements; i++) {
    max = std::max(max, elements[i]);
  }

  int result = max;

  for (int li = 1, ri = max; li <= ri;) {
    int mid = li + (ri - li) / 2;

    int j = 0;
    for (int i = 0, c = 0; i < num_elements && j < num_groups; i++) {
      if (elements[i] <= mid) {
        c++;
      } else {
        c = 0;
      }

      if (c == groups[j]) {
        j++;
        c = 0;
      }
    }

    bool success = j == num_groups;

    if (success) {
      result = std::min(result, mid);
      ri = mid - 1;
    } else {
      li = mid + 1;
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T = 0;
  std::cin >> T;

  for (int t = 1; t <= T; t++) {
    std::cin >> num_elements >> num_groups;

    for (int i = 0; i < num_elements; i++) {
      std::cin >> elements[i];
    }

    for (int i = 0; i < num_groups; i++) {
      std::cin >> groups[i];
    }

    std::cout << '#' << t << ' ' << solution() << '\n';
  }

  return 0;
}
