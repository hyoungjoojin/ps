#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    for (int li = 0, ri = nums.size() - 1; li <= ri;) {
      int mid = li + (ri - li) / 2;

      if (nums[mid] < target) {
        li = mid + 1;
      } else if (nums[mid] > target) {
        ri = mid - 1;
      } else {
        return mid;
      }
    }

    return -1;
  }
};
