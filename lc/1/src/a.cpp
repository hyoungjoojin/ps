#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> m;
    vector<int> result(2);

    for (int i = 0; i < nums.size(); i++) {
      auto it = m.find(target - nums[i]);

      if (it == m.end()) {
        m[nums[i]] = i;
      } else {
        result[0] = it->second;
        result[1] = i;
        break;
      }
    }

    return result;
  }
};
