// 9 ms, 26.91 MB

#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int majority_candidate = 0, count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (count == 0)
        majority_candidate = nums[i];
      count += (majority_candidate == nums[i] ? 1 : -1);
    }

    return majority_candidate;
  }
};
