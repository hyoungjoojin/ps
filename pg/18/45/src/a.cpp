#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
  unordered_map<int, int> count;
  for (int num : nums) {
    count[num]++;
  }

  return min(nums.size() / 2, count.size());
}
