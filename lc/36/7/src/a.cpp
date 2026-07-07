using ll = long long;

class Solution {
public:
  bool isPerfectSquare(int num) {
    for (int li = 0, ri = num; li <= ri;) {
      ll root = li + (ri - li) / 2;
      ll square = root * root;

      if (square < num) {
        li = root + 1;
      } else if (square > num) {
        ri = root - 1;
      } else {
        return true;
      }
    }

    return false;
  }
};
