#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <string>

using namespace std;

int get_op_index(char op) {
  if (op == '+') {
    return 0;
  } else if (op == '-') {
    return 1;
  } else {
    return 2;
  }
}

long long calculate(long long x, long long y, char op) {
  if (op == '+') {
    return x + y;
  } else if (op == '-') {
    return x - y;
  } else {
    return x * y;
  }
}

long long evaluate(string &expression, int order[3]) {
  stack<long long> s;
  stack<char> op;
  long long n = 0;

  for (char ch : expression) {
    if (isdigit(ch)) {
      n = (n * 10) + (ch - '0');
      continue;
    }

    s.push(n);
    n = 0;

    while (!op.empty() &&
           order[get_op_index(op.top())] >= order[get_op_index(ch)]) {
      long long y = s.top();
      s.pop();

      long long x = s.top();
      s.pop();

      s.push(calculate(x, y, op.top()));
      op.pop();
    }

    op.push(ch);
  }

  s.push(n);

  while (!op.empty()) {
    long long y = s.top();
    s.pop();

    long long x = s.top();
    s.pop();

    s.push(calculate(x, y, op.top()));
    op.pop();
  }

  return s.top();
}

long long solution(string expression) {
  int permutation[3] = {1, 2, 3};
  long long result = 0;

  do {
    result = max(result, abs(evaluate(expression, permutation)));
  } while (next_permutation(permutation, permutation + 3));

  return result;
}
