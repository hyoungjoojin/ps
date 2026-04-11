#include <string>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int frequency[26] = {0};

    for (int i = 0; i < s.length(); i++) {
      frequency[s[i] - 'a']++;
    }

    for (int i = 0; i < t.length(); i++) {
      frequency[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
      if (frequency[i] != 0) {
        return false;
      }
    }

    return true;
  }
};
