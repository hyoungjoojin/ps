#include <algorithm>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
  string addStrings(string num1, string num2) {
    int l1 = num1.length(), l2 = num2.length();
    int c1, c2, carry = 0;

    string result = "";

    for (c1 = l1 - 1, c2 = l2 - 1; c1 >= 0 && c2 >= 0; c1--, c2--) {
      int sum = (num1[c1] - '0') + (num2[c2] - '0') + carry;
      if (sum >= 10) {
        sum -= 10;
        carry = 1;
      } else {
        carry = 0;
      }

      result += (sum + '0');
    }

    for (; c1 >= 0; c1--) {
      int sum = (num1[c1] - '0') + carry;
      if (sum >= 10) {
        sum -= 10;
        carry = 1;
      } else {
        carry = 0;
      }

      result += (sum + '0');
    }

    for (; c2 >= 0; c2--) {
      int sum = (num2[c2] - '0') + carry;
      if (sum >= 10) {
        sum -= 10;
        carry = 1;
      } else {
        carry = 0;
      }

      result += (sum + '0');
    }

    if (carry) {
      result += '1';
    }

    for (int li = 0, ri = result.length() - 1; li < ri; li++, ri--) {
      swap(result[li], result[ri]);
    }

    return result;
  }
};
