// 8ms, 21.27 MB

#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    unsigned int count = 1;

    int current_value = nums[0];
    for (unsigned int i = 0; i < nums.size(); i++) {
      if (current_value == nums[i])
        continue;

      current_value = nums[i];
      swap(nums[count++], nums[i]);
    }

    return count;
  }
};
