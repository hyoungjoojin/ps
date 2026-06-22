#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
  unordered_map<string, int> m;
  for (int i = 0, f = 0; f < friends.size(); f++) {
    if (m.find(friends[f]) == m.end()) {
      m[friends[f]] = i++;
    }
  }

  int n = friends.size();
  vector<int> k(n, 0);
  vector<vector<int>> adjacency(n, vector<int>(n, 0));

  for (string &gift : gifts) {
    int split = gift.find(' ');
    string a = gift.substr(0, split), b = gift.substr(split + 1);
    int ai = m[a], bi = m[b];

    k[ai]++;
    k[bi]--;
    adjacency[ai][bi]++;
  }

  int result = 0;

  for (int i = 0; i < n; i++) {
    int count = 0;

    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }

      int ij = adjacency[i][j], ji = adjacency[j][i];
      if (ij > ji) {
        count++;
      } else if (ij == ji && k[i] > k[j]) {
        count++;
      }
    }

    result = max(result, count);
  }

  return result;
}
