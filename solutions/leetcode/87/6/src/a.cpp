struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    int length = 0;

    ListNode *current = head;
    while (current != nullptr) {
      length++;
      current = current->next;
    }

    int middle = length / 2;
    current = head;

    while (middle--) {
      current = current->next;
    }

    return current;
  }
};
