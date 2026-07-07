extern int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    for (int li = 1, ri = n; li <= ri;) {
      int t = li + (ri - li) / 2;

      int result = guess(t);
      if (result == -1) {
        ri = t - 1;
      } else if (result == 1) {
        li = t + 1;
      } else {
        return t;
      }
    }

    return -1;
  }
};
