#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    if (n <= 9) {
      return n;
    }

    vector<int> digits;

    int t = n;
    while (t) {
      digits.push_back(t % 10);
      t /= 10;
    }

    for (int li = 0, ri = digits.size() - 1; li < ri; li++, ri--) {
      swap(digits[li], digits[ri]);
    }

    for (int i = 0; i < digits.size() - 1; i++) {
      bool decreasing = (digits[i + 1] < digits[i]);
      if (!decreasing) {
        continue;
      }

      while (i > 0 && digits[i] == digits[i - 1]) {
        i--;
      }

      digits[i] = digits[i] - 1;
      while (++i < digits.size()) {
        digits[i] = 9;
      }
    }

    int result = 0;
    for (int i = 0; i < digits.size(); i++) {
      result *= 10;
      result += digits[i];
    }

    return result;
  }
};
