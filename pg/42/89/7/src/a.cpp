#include <algorithm>
#include <vector>

using namespace std;

int get_maximum_value(vector<int> &money, int start, int end) {
  int take = 0, skip = 0;
  for (int i = start; i < end; i++) {
    int temp = skip + money[i];
    skip = max(take, skip);
    take = temp;
  }

  return max(take, skip);
}

int solution(vector<int> money) {
  int n = money.size();
  return max(get_maximum_value(money, 0, n - 1),
             get_maximum_value(money, 1, n));
}
