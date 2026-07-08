#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());

    int boats = 0;
    for (int li = 0, ri = people.size() - 1; li <= ri; boats++, ri--) {
      if (people[li] + people[ri] <= limit) {
        li++;
      }
    }

    return boats;
  }
};
