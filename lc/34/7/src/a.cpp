#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    for (int i : nums) {
      freq[i]++;
    }

    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (auto [i, f] : freq) {
      pq.push({f, i});

      if (pq.size() > k) {
        pq.pop();
      }
    }

    while (!pq.empty()) {
      result.push_back(pq.top().second);
      pq.pop();
    }

    return result;
  }
};
