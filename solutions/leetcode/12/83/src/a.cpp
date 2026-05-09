#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int m = numeric_limits<int>::max();

    for (int li = 1, ri = numeric_limits<int>::max(); li <= ri;) {
      int mid = li + (ri - li) / 2;

      int sum = 0;
      for (int i : nums) {
        sum += (i / mid) + (i % mid == 0 ? 0 : 1);
      }

      if (sum > threshold) {
        li = mid + 1;
      } else {
        ri = mid - 1;
        m = min(m, mid);
      }
    }

    return m;
  }
};
