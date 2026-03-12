#include <iostream>

int _get_index_recursive(int length, int base_r, int base_c, int r, int c) {
  if (length == 1) {
    return 0;
  }

  int half_length = length / 2;
  int square = half_length * half_length;

  int index = 0;

  if (r >= base_r + half_length) {
    if (c >= base_c + half_length) {
      index += square * 3;
      index += _get_index_recursive(half_length, base_r + half_length,
                                    base_c + half_length, r, c);

    } else {
      index += square * 2;
      index +=
          _get_index_recursive(half_length, base_r + half_length, base_c, r, c);
    }
  } else {
    if (c >= base_c + half_length) {
      index += square;
      index +=
          _get_index_recursive(half_length, base_r, base_c + half_length, r, c);
    } else {
      index += _get_index_recursive(half_length, base_r, base_c, r, c);
    }
  }

  return index;
}

int get_index(int n, int r, int c) {
  int length = 1 << n;
  return _get_index_recursive(length, 0, 0, r, c);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, r, c;
  std::cin >> n >> r >> c;

  std::cout << get_index(n, r, c) << '\n';

  return 0;
}
