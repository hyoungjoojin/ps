#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findGoodIntegers(int n) {
    map<int, int> combinations;
    vector<int> roots;
    vector<int> result;

    for (int i = 1, cube = 1; cube <= n; i++, cube = i * i * i) {
      roots.push_back(cube);
    }

    for (int i = 0; i < roots.size(); i++) {
      for (int j = i + 1; j < roots.size(); j++) {
        int sum = roots[i] + roots[j];
        if (sum <= n) {
          combinations[sum]++;
        }
      }
    }

    for (auto it = combinations.begin(); it != combinations.end(); it++) {
      int x = it->first, count = it->second;

      if (count > 1) {
        result.push_back(x);
      }
    }

    return result;
  }
};
