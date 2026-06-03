#include <functional>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) : k(k), pq() {
    for (int i : nums) {
      pq.push(i);
      if (pq.size() > k) {
        pq.pop();
      }
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > k) {
      pq.pop();
    }

    return pq.top();
  }

private:
  int k;
  priority_queue<int, vector<int>, greater<>> pq;
};
