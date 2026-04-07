#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int result = 1;
    for (auto it = lower_bound(nums.begin(), nums.end(), 1); it != nums.end();
         it++) {
      if (*it == result) {
        result++;
      } else if (*it > result) {
        break;
      }
    }

    return result;
  }
};
