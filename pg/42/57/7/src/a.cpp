#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
  sort(phone_book.begin(), phone_book.end());

  for (int i = 1; i < phone_book.size(); i++) {
    string &s = phone_book[i - 1], &t = phone_book[i];

    if (t.length() < s.length()) {
      continue;
    }

    bool starts_with = true;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] != t[j]) {
        starts_with = false;
        break;
      }
    }

    if (starts_with) {
      return false;
    }
  }

  return true;
}
