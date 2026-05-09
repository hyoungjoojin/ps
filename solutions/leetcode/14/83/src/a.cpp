#include <vector>

using namespace std;

class TreeAncestor {
public:
  TreeAncestor(int n, vector<int> &parent) {
    L = 0;
    while ((1 << L) <= n) {
      L++;
    }

    up = vector<vector<int>>(n, vector<int>(L));
    depth = vector<int>(n, -1);

    for (int i = 0; i < n; i++) {
      up[i][0] = parent[i];
    }

    for (int i = 0; i < n; i++) {
      compute_depth(i, parent);
    }

    for (int d = 1; d < L; d++) {
      for (int i = 0; i < n; i++) {
        up[i][d] = up[up[i][d - 1]][d - 1];
      }
    }
  }

  int getKthAncestor(int node, int k) {
    if (k > depth[node]) {
      return -1;
    }

    for (int d = 0; d < L; d++) {
      if (k & (1 << d)) {
        node = up[node][d];
      }
    }

    return node;
  }

private:
  int L;
  vector<vector<int>> up;
  vector<int> depth;

  int compute_depth(int node, vector<int> &parent) {
    if (depth[node] != -1) {
      return depth[node];
    }

    if (parent[node] == -1) {
      return depth[node] = 0;
    }

    return depth[node] = compute_depth(parent[node], parent) + 1;
  }
};
