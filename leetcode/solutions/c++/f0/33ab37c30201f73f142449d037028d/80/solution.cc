// 0 ms, 13.47 MB

#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int current_index = 0, count = 0, current_value = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (i == 0 || current_value != nums[i]) {
        current_value = nums[i];
        count = 0;
      }

      if (++count > 2)
        continue;

      swap(nums[i], nums[current_index++]);
    }

    return current_index;
  }
};
