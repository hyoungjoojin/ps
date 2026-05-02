#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    int num_points = points.size();

    for (int i = 0; i < num_points; i++) {
      int x = points[i][0], y = points[i][1];
      int d = (x * x) + (y * y);
      points[i].push_back(d);
    }

    sort(points.begin(), points.end(),
         [](const vector<int> &p1, const vector<int> &p2) {
           return p1[2] < p2[2];
         });

    vector<vector<int>> result;
    for (int i = 0; i < k; i++) {
      int x = points[i][0], y = points[i][1];
      vector<int> point = {x, y};
      result.push_back(point);
    }

    return result;
  }
};
