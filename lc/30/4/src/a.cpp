#include <vector>

using namespace std;

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> &matrix)
      : m(matrix.size()), n(matrix[0].size()),
        psum(m + 1, vector<int>(n + 1, 0)) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        psum[i + 1][j + 1] = matrix[i][j] + psum[i + 1][j];
      }

      for (int j = 0; j < n; j++) {
        psum[i + 1][j + 1] += psum[i][j + 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return psum[row2 + 1][col2 + 1] - psum[row1][col2 + 1] -
           psum[row2 + 1][col1] + psum[row1][col1];
  }

private:
  int m;
  int n;
  vector<vector<int>> psum;
};
