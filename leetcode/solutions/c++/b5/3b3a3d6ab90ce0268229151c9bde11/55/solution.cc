// 44 ms, 51.19 MB

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int maximum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > maximum)
        return false;

      maximum = max(maximum, i + nums[i]);
    }

    return true;
  }
};
