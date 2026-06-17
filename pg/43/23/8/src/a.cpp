#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
  long long maximum = static_cast<long long>(times[0]) * n;
  long long answer = maximum;

  for (long long li = 0, ri = maximum; li <= ri;) {
    long long time = li + (ri - li) / 2;

    long long count = 0;
    for (int &i : times) {
      count += (time / i);
    }

    if (count >= n) {
      answer = min(answer, time);
      ri = time - 1;
    } else {
      li = time + 1;
    }
  }

  return answer;
}
