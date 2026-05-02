struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *root = new ListNode();
    ListNode *p1 = list1, *p2 = list2, *p = root;

    while (p1 != nullptr && p2 != nullptr) {
      int v1 = p1->val, v2 = p2->val;
      if (v1 < v2) {
        p->next = new ListNode(v1);
        p1 = p1->next;
      } else {
        p->next = new ListNode(v2);
        p2 = p2->next;
      }

      p = p->next;
    }

    while (p1 != nullptr) {
      int v = p1->val;
      p->next = new ListNode(v);
      p1 = p1->next;
      p = p->next;
    }

    while (p2 != nullptr) {
      int v = p2->val;
      p->next = new ListNode(v);
      p2 = p2->next;
      p = p->next;
    }

    ListNode *result = root->next;
    delete root;
    return result;
  }
};
