#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    set<int> dictionary;

    for (int i = 0; i < nums.size(); i++) {
      if (dictionary.find(nums[i]) == dictionary.end()) {
        dictionary.insert(nums[i]);
      } else {
        return false;
      }
    }

    return true;
  }
};
