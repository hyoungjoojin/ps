#include <vector>

using namespace std;

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int n = nums.size();

    for (int li = 0, ri = n - 1; li <= ri;) {
      int target = li + (ri - li) / 2;

      if (target > 0 && nums[target - 1] == nums[target]) {
        target--;
      }

      if (target + 1 >= n || nums[target] != nums[target + 1]) {
        return nums[target];
      }

      if (target % 2 == 1) {
        ri = target - 1;
      } else {
        li = target + 2;
      }
    }

    return -1;
  }
};
