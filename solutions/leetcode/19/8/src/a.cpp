#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    } else if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }

    vector<int> memo(nums.size());
    memo[0] = nums[0];
    memo[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
      memo[i] = max(nums[i] + memo[i - 2], memo[i - 1]);
    }

    return memo[nums.size() - 1];
  }
};
