#include <string>

using namespace std;

class Solution {
public:
  bool validPalindrome(string s) {
    return _validPalindrome(s, 0, s.length() - 1, true);
  }

private:
  bool _validPalindrome(string &s, int start, int end, bool erasable) {
    if (start >= end) {
      return true;
    }

    if (s[start] == s[end]) {
      return _validPalindrome(s, start + 1, end - 1, erasable);
    }

    if (!erasable) {
      return false;
    }

    bool valid = false;
    valid = valid || _validPalindrome(s, start, end - 1, false);
    valid = valid || _validPalindrome(s, start + 1, end, false);

    return valid;
  }
};
