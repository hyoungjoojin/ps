#include <queue>

using namespace std;

class MyStack {
public:
  MyStack() {}

  void push(int x) { q.push(x); }

  int pop() {
    for (int i = 0; i < q.size() - 1; i++) {
      int front = q.front();
      q.pop();
      q.push(front);
    }

    int front = q.front();
    q.pop();
    return front;
  }

  int top() {
    int front = pop();
    q.push(front);
    return front;
  }

  bool empty() { return q.empty(); }

private:
  queue<int> q;
};
