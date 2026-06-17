#include <functional>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

vector<int> solution(vector<string> gems) {
  unordered_map<string, int> m;

  int n = 0;
  for (int i = 0; i < gems.size(); i++) {
    if (m.find(gems[i]) == m.end()) {
      m[gems[i]] = n++;
    }
  }

  vector<int> recent(n, -1);

  int i = 0;

  for (int k = 0; i < gems.size() && k < n; i++) {
    int g = m[gems[i]];
    if (recent[g] == -1) {
      k++;
    }

    recent[g] = i;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  for (int g = 0; g < n; g++) {
    pq.push({recent[g], g});
  }

  int minimum = i - pq.top().first;
  vector<int> answer = {pq.top().first + 1, i};

  for (; i < gems.size(); i++) {
    int g = m[gems[i]];

    recent[g] = i;
    pq.push({i, g});

    while (!pq.empty()) {
      auto [index, gem] = pq.top();
      if (recent[gem] != index) {
        pq.pop();
      } else {
        break;
      }
    }

    int len = i - pq.top().first + 1;
    if (minimum > len) {
      minimum = len;
      answer[0] = pq.top().first + 1;
      answer[1] = i + 1;
    }
  }

  return answer;
}
