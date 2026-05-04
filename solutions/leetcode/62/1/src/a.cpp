#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    priority_queue<pair<int, int>> ready;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
        processing;

    int total_leftovers = tasks.size();
    int leftovers[26] = {0};

    for (char ch : tasks) {
      leftovers[ch - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
      if (leftovers[i] > 0) {
        ready.push({leftovers[i], i});
      }
    }

    int time = 0;
    while (total_leftovers > 0) {
      time++;

      while (!processing.empty() && processing.top().first < time) {
        int index = processing.top().second;
        processing.pop();
        ready.push({leftovers[index], index});
      }

      if (ready.empty()) {
        continue;
      }

      int index = ready.top().second;
      ready.pop();

      total_leftovers--;
      if (--leftovers[index] > 0) {
        processing.push({time + n, index});
      }
    }

    return time;
  }
};
