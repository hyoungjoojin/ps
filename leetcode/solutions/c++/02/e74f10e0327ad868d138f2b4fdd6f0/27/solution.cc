// 0 ms, 10.5 MB

#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int result = 0;
    int front_index = 0, back_index = nums.size() - 1;

    while (front_index <= back_index) {
      if (nums[front_index] == val) {
        swap(nums[front_index], nums[back_index--]);
      } else {
        front_index++;
        result++;
      }
    }

    return result;
  }
};
