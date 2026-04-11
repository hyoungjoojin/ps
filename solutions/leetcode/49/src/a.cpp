#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> result;

    unordered_map<string, int> group_map;
    int num_groups = 0;

    for (int i = 0; i < strs.size(); i++) {
      string anagram = strs[i];
      sort(anagram.begin(), anagram.end());

      int group = 0;

      if (group_map.find(anagram) == group_map.end()) {
        group = num_groups++;
        group_map[anagram] = group;
        result.push_back(vector<string>());
      } else {
        group = group_map[anagram];
      }

      result[group].push_back(strs[i]);
    }

    return result;
  }
};
