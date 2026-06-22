#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  unordered_map<string, int> m;

  for (string &s : participant) {
    m[s]++;
  }

  for (string &s : completion) {
    m[s]--;
  }

  for (auto &[name, count] : m) {
    if (count == 1) {
      return name;
    }
  }

  return "";
}
