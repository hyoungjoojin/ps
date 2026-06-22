#include <string>
#include <utility>
#include <vector>

using namespace std;

string parse(long long number) {
  string target = "";
  while (number) {
    target += (number & 1 ? '1' : '0');
    number >>= 1;
  }

  int depth = 1;
  while ((1 << depth) - 1 < target.length()) {
    depth++;
  }

  for (int i = target.length(); i < (1 << depth) - 1; i++) {
    target += '0';
  }

  for (int li = 0, ri = target.length() - 1; li < ri; li++, ri--) {
    swap(target[li], target[ri]);
  }

  return target;
}

bool valid(string &s, int start, int end) {
  if (start == end) {
    return true;
  }

  int mid = start + (end - start) / 2;
  if (s[mid] == '0') {
    for (int i = start; i <= end; i++) {
      if (s[i] == '1') {
        return false;
      }
    }

    return true;
  } else {
    return valid(s, start, mid - 1) && valid(s, mid + 1, end);
  }
}

vector<int> solution(vector<long long> numbers) {
  vector<int> result;

  for (auto number : numbers) {
    string s = parse(number);
    result.push_back(valid(s, 0, s.length() - 1) ? 1 : 0);
  }

  return result;
}
