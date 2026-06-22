#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> sets;

void parse_set(string &s) {
  vector<int> set;

  int x = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ',') {
      set.push_back(x);
      x = 0;
    } else {
      x *= 10;
      x += (s[i] - '0');
    }
  }

  set.push_back(x);
  sets.push_back(set);
}

void parse(string &s) {
  for (int i = 2; i < s.length() - 1; i += 3) {
    string set = "";
    while (s[i] != '}') {
      set += s[i++];
    }

    parse_set(set);
  }
}

vector<int> solution(string s) {
  parse(s);

  sort(sets.begin(), sets.end(),
       [](vector<int> &v1, vector<int> &v2) { return v1.size() < v2.size(); });

  vector<int> result;
  set<int> numbers;

  for (auto &set : sets) {
    for (int i : set) {
      if (numbers.find(i) == numbers.end()) {
        result.push_back(i);
        numbers.insert(i);
        break;
      }
    }
  }

  return result;
}
