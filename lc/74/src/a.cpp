#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> col(m);
    for (int i = 0; i < m; i++) {
      col[i] = matrix[i][0];
    }

    int row = upper_bound(col.begin(), col.end(), target) - col.begin() - 1;
    if (row < 0) {
      return false;
    }

    return binary_search(matrix[row].begin(), matrix[row].end(), target);
  }
};
