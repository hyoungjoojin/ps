#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> parens;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        parens.push(s[i]);
        continue;
      }

      if (parens.empty()) {
        return false;
      }

      char counterpart;

      switch (s[i]) {
      case ')':
        counterpart = '(';
        break;

      case '}':
        counterpart = '{';
        break;

      case ']':
        counterpart = '[';
        break;
      }

      if (parens.top() == counterpart) {
        parens.pop();
      } else {
        return false;
      }
    }

    return parens.empty();
  }
};
