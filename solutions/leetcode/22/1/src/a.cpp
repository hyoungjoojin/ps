#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));

    int result = 0;

    for (int r = 0; r < m; r++) {
      memo[r][0] = (matrix[r][0] == '1' ? 1 : 0);
      result = max(result, memo[r][0]);
    }

    for (int c = 0; c < n; c++) {
      memo[0][c] = (matrix[0][c] == '1' ? 1 : 0);
      result = max(result, memo[0][c]);
    }

    for (int r = 1; r < m; r++) {
      for (int c = 1; c < n; c++) {
        if (matrix[r][c] == '0') {
          memo[r][c] = 0;
        } else {
          int l = min(memo[r - 1][c], memo[r][c - 1]);
          l = min(l, memo[r - 1][c - 1]);
          memo[r][c] = l + 1;
        }

        result = max(result, memo[r][c]);
      }
    }

    return result * result;
  }
};
