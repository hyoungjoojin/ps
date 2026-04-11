#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    const int MIN = -10000, MAX = 10000;
    int frequency_array[MAX - MIN + 1] = {0};

    for (int i = 0; i < nums.size(); i++) {
      frequency_array[nums[i] - MIN]++;
    }

    for (int i = 0; i < MAX - MIN + 1; i++) {
      if (frequency_array[i] == 0) {
        continue;
      }

      pq.push({frequency_array[i], i + MIN});
      if (pq.size() > k) {
        pq.pop();
      }
    }

    while (!pq.empty()) {
      int value = pq.top().second;
      pq.pop();

      result.push_back(value);
    }

    return result;
  }
};
