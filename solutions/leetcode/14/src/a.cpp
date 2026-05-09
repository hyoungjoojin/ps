#include <algorithm>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int min_length = numeric_limits<int>::max();
    for (string &str : strs) {
      min_length = min(min_length, static_cast<int>(str.length()));
    }

    string prefix = "";

    for (int l = 0; l < min_length; l++) {
      char ch = strs[0][l];
      bool equals = true;

      for (string &str : strs) {
        if (ch != str[l]) {
          equals = false;
          break;
        }
      }

      if (!equals) {
        break;
      }

      prefix += ch;
    }

    return prefix;
  }
};
