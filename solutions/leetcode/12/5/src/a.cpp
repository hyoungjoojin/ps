#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    for (int li = 0, ri = s.length() - 1; li < ri;) {
      char left = s[li], right = s[ri];

      if (!isalpha(left) && !isdigit(left)) {
        li++;
        continue;
      } else if (!isalpha(right) && !isdigit(right)) {
        ri--;
        continue;
      }

      if ('A' <= left && left <= 'Z') {
        left = 'a' + (left - 'A');
      }

      if ('A' <= right && right <= 'Z') {
        right = 'a' + (right - 'A');
      }

      if (left != right) {
        return false;
      }

      li++;
      ri--;
    }

    return true;
  }
};
