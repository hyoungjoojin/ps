#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> tails;

    for (int i : nums) {
      auto lb = lower_bound(tails.begin(), tails.end(), i);
      if (lb == tails.end()) {
        tails.push_back(i);
      } else {
        *lb = i;
      }
    }

    return tails.size();
  }
};
