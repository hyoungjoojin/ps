#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int result = *max_element(piles.begin(), piles.end());

    for (int li = 1, ri = result; li <= ri;) {
      int k = li + (ri - li) / 2;

      ll time = 0;
      for (int &pile : piles) {
        time += (pile + k - 1) / k;
      }

      if (time <= h) {
        result = min(result, k);
        ri = k - 1;
      } else {
        li = k + 1;
      }
    }

    return result;
  }
};
