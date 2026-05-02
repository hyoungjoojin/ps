#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    auto cmp = [&x](int &a, int &b) {
      int da = abs(a - x), db = abs(b - x);
      if (da == db) {
        return a < b;
      } else {
        return da < db;
      }
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int &i : arr) {
      pq.push(i);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<int> result;
    while (!pq.empty()) {
      result.push_back(pq.top());
      pq.pop();
    }

    sort(result.begin(), result.end());
    return result;
  }
};
