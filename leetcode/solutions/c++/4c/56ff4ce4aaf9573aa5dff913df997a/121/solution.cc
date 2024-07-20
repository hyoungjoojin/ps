// 90 ms, 96.28 MB

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int max_value = 0, min_value = (~0L >> 1);
    for (auto &price : prices) {
      min_value = min(min_value, price);
      max_value = max(max_value, price - min_value);
    }

    return max_value;
  }
};
