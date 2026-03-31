struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *root = new ListNode(0);

    ListNode *current = root;
    int sum = 0, carry = 0;

    while (l1 != nullptr && l2 != nullptr) {
      sum = l1->val + l2->val + carry;
      carry = sum / 10;
      sum = sum % 10;

      current->next = new ListNode(sum);
      current = current->next;

      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1 != nullptr) {
      sum = l1->val + carry;
      carry = sum / 10;
      sum = sum % 10;

      current->next = new ListNode(sum);
      current = current->next;

      l1 = l1->next;
    }

    while (l2 != nullptr) {
      sum = l2->val + carry;
      carry = sum / 10;
      sum = sum % 10;

      current->next = new ListNode(sum);
      current = current->next;

      l2 = l2->next;
    }

    if (carry) {
      current->next = new ListNode(carry);
    }

    ListNode *result = root->next;
    delete root;
    return result;
  }
};
