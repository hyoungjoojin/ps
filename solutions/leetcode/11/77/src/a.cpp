#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
    array<int, 26> freq;
    vector<int> psum[26];

    for (char ch : s) {
      for (int i = 0; i < 26; i++) {
        psum[i].push_back(freq[i]);
      }

      freq[ch - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      psum[i].push_back(freq[i]);
    }

    vector<bool> result(queries.size());

    for (int q = 0; q < queries.size(); q++) {
      int l = queries[q][0], r = queries[q][1];
      int k = queries[q][2], required_k = 0;

      for (int i = 0; i < 26; i++) {
        int f = psum[i][r + 1] - psum[i][l];
        if (f % 2 == 1) {
          required_k++;
        }
      }

      required_k /= 2;

      result[q] = (k >= required_k);
    }

    return result;
  }
};
