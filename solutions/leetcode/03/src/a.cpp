#include <algorithm>
#include <array>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;
    std::array<int, 256> frequency = {0};

    for (int li = 0, ri = 0; ri < s.length(); ri++) {
      if (++frequency[s[ri]] > 1) {
        while (s[li] != s[ri]) {
          frequency[s[li]]--;
          li++;
        }

        frequency[s[li]]--;
        li++;
      }

      result = max(ri - li + 1, result);
    }

    return result;
  }
};
