#include <cstdlib>
#include <string>
#include <utility>
#include <vector>

using namespace std;

constexpr int LEFT[3] = {1, 4, 7}, RIGHT[3] = {3, 6, 9}, MID[4] = {2, 5, 8, 0};

int distance(pair<int, int> &x, pair<int, int> &y) {
  return abs(x.first - y.first) + abs(x.second - y.second);
}

string solution(vector<int> numbers, string hand) {
  string answer = "";

  pair<int, int> left = {3, 0}, right = {3, 2};

  for (int number : numbers) {
    bool found = false;

    for (int i = 0; i < 3; i++) {
      if (number == LEFT[i]) {
        left = {i, 0};
        found = true;
        answer += 'L';
      }
    }

    if (found) {
      continue;
    }

    for (int i = 0; i < 3; i++) {
      if (number == RIGHT[i]) {
        right = {i, 2};
        found = true;
        answer += 'R';
      }
    }

    if (found) {
      continue;
    }

    pair<int, int> p;
    for (int i = 0; i < 4; i++) {
      if (number == MID[i]) {
        p = {i, 1};
        break;
      }
    }

    int dl = distance(p, left), dr = distance(p, right);
    if (dl > dr) {
      right = p;
      answer += 'R';
    } else if (dl < dr) {
      left = p;
      answer += 'L';
    } else if (hand == "right") {
      right = p;
      answer += 'R';
    } else {
      left = p;
      answer += 'L';
    }
  }

  return answer;
}
