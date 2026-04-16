#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    k %= nums.size();

    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
  }

private:
  void reverse(vector<int> &nums, int start, int end) {
    for (int li = start, ri = end; li < ri; li++, ri--) {
      swap(nums[li], nums[ri]);
    }
  }
};
