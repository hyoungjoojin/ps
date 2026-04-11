#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result(2, -1);
    map<int, int> dictionary;

    for (int i = 0; i < nums.size(); i++) {
      int remainder = target - nums[i];

      if (dictionary.find(remainder) != dictionary.end()) {
        result[0] = dictionary[remainder];
        result[1] = i;
        break;
      } else {
        dictionary[nums[i]] = i;
      }
    }

    return result;
  }
};
