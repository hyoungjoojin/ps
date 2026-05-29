#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
      if (ch == ')' || ch == '}' || ch == ']') {
        if (!st.empty() && st.top() == ch) {
          st.pop();
        } else {
          return false;
        }
      } else {
        switch (ch) {
        case '(':
          st.push(')');
          break;

        case '{':
          st.push('}');
          break;

        case '[':
          st.push(']');
          break;
        }
      }
    }

    return st.empty();
  }
};
