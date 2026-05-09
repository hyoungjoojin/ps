#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s;
    for (int i : nums) {
      s.insert(i);
    }

    int max_length = 0;
    for (int i : s) {
      if (s.find(i - 1) != s.end()) {
        continue;
      }

      int length = 1;
      while (s.find(i + length) != s.end()) {
        length++;
      }

      max_length = max(max_length, length);
    }

    return max_length;
  }
};
