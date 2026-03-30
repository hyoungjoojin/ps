#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
  int appendCharacters(string s, string t) {
    int result = t.length();

    for (int si = 0, ti = 0; si < s.length() && ti < t.length(); si++) {
      if (s[si] == t[ti]) {
        ti++;
        result--;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;
  assert(solution.appendCharacters("coaching", "coding") == 4);
  assert(solution.appendCharacters("abcde", "a") == 0);
  assert(solution.appendCharacters("z", "abcde") == 5);
}
