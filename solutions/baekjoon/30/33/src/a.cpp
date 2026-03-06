#include <algorithm>
#include <iostream>
#include <string>

const int MAX_N = 200001;

std::string S;
int N;
int gap;
int SA[MAX_N], RA[MAX_N], TA[MAX_N];
int LCP[MAX_N];

bool suffix_array_cmp(int i, int j) {
  if (RA[i] != RA[j]) {
    return RA[i] < RA[j];
  }

  i += gap;
  j += gap;
  return (i < N && j < N) ? RA[i] < RA[j] : i > j;
}

void build_suffix_array() {
  for (int i = 0; i < N; i++) {
    SA[i] = i;
    RA[i] = S[i];
  }

  for (gap = 1;; gap *= 2) {
    std::sort(SA, SA + N, suffix_array_cmp);

    TA[0] = 0;
    for (int i = 0; i < N - 1; i++) {
      TA[i + 1] = TA[i] + suffix_array_cmp(SA[i], SA[i + 1]);
    }

    for (int i = 0; i < N; i++) {
      RA[SA[i]] = TA[i];
    }

    if (TA[N - 1] == N - 1) {
      break;
    }
  }
}

void build_lcp_array() {
  for (int i = 0, k = 0; i < N; i++, k = std::max(k - 1, 0)) {
    if (RA[i] == N - 1) {
      continue;
    }

    for (int j = SA[RA[i] + 1]; S[i + k] == S[j + k]; k++)
      ;

    LCP[RA[i]] = k;
  }
}

int get_longest_repeating_substring_length() {
  return *std::max_element(LCP, LCP + N);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;
  std::cin >> S;

  build_suffix_array();
  build_lcp_array();

  std::cout << get_longest_repeating_substring_length() << '\n';

  return 0;
}
