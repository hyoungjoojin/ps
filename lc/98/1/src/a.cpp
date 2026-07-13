#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
public:
  TimeMap() { N = 0; }

  void set(string key, string value, int timestamp) {
    int k = get_k(key);
    timestamps[k].push_back(timestamp);
    values[k].push_back(value);
  }

  string get(string key, int timestamp) {
    int k = get_k(key, false);
    if (k == -1) {
      return "";
    }

    int t = upper_bound(timestamps[k].begin(), timestamps[k].end(), timestamp) -
            timestamps[k].begin() - 1;

    if (t < 0) {
      return "";
    }

    return values[k][t];
  }

private:
  static const int MAX_N = 101;

  int N;
  unordered_map<string, int> keys;
  vector<int> timestamps[MAX_N];
  vector<string> values[MAX_N];

  int get_k(string &key, bool insert = true) {
    if (keys.find(key) != keys.end()) {
      return keys[key];
    } else if (insert) {
      int k = N++;
      keys[key] = k;
      timestamps[k].clear();
      values[k].clear();
      return k;
    } else {
      return -1;
    }
  }
};
