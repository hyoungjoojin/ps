#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<ListNode *> pointers(lists.size());

    for (int i = 0; i < lists.size(); i++) {
      if (lists[i] != nullptr) {
        pq.push({lists[i]->val, i});
        pointers[i] = lists[i]->next;
      }
    }

    ListNode *root = new ListNode();
    ListNode *current = root;

    while (!pq.empty()) {
      int value = pq.top().first, index = pq.top().second;
      pq.pop();

      current->next = new ListNode(value);
      current = current->next;

      if (pointers[index] != nullptr) {
        pq.push({pointers[index]->val, index});
        pointers[index] = pointers[index]->next;
      }
    }

    ListNode *result = root->next;
    delete root;

    return result;
  }
};
