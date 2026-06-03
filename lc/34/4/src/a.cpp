#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    for (int li = 0, ri = s.size() - 1; li < ri; li++, ri--) {
      swap(s[li], s[ri]);
    }
  }
};
