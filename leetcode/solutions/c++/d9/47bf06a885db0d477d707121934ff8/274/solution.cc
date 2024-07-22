// 3 ms, 11.07 MB

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    if (citations.size() == 1)
      return citations[0] > 0 ? 1 : 0;

    sort(citations.begin(), citations.end());

    int result = 0;
    for (int i = citations.size() - 1; i >= 0; i--) {
      int minimum = min(static_cast<int>(citations.size()) - i, citations[i]);
      result = max(result, minimum);
    }

    return result;
  }
};
