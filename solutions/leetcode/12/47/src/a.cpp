#include <string>

using namespace std;

class Solution {
public:
  int minimumSwap(string s1, string s2) {
    int xy_count = 0, yx_count = 0;
    for (int i = 0; i < s1.length(); i++) {
      if (s1[i] == s2[i]) {
        continue;
      } else if (s1[i] == 'x') {
        xy_count++;
      } else if (s1[i] == 'y') {
        yx_count++;
      }
    }

    if ((xy_count + yx_count) % 2 != 0) {
      return -1;
    }

    return (xy_count / 2 + xy_count % 2) + (yx_count / 2 + yx_count % 2);
  }
};
