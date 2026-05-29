#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
    int m = mat.size(), n = mat[0].size();

    vector<vector<int>> psum(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        psum[i + 1][j + 1] = psum[i + 1][j] + mat[i][j];
      }

      for (int j = 0; j < n; j++) {
        psum[i + 1][j + 1] += psum[i][j + 1];
      }
    }

    vector<vector<int>> result(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int r1 = max(0, i - k), r2 = min(m - 1, i + k) + 1;
        int c1 = max(0, j - k), c2 = min(n - 1, j + k) + 1;

        result[i][j] =
            psum[r2][c2] - psum[r2][c1] - psum[r1][c2] + psum[r1][c1];
      }
    }

    return result;
  }
};
