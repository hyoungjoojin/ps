#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int g = nums[0], c = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      c = max(c + nums[i], nums[i]);
      g = max(g, c);
    }

    return g;
  }
};
