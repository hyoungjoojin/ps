#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    const int MIN = -30, MAX = 30;
    int freqency_array[MAX - MIN + 1] = {0};

    for (int i = 0; i < nums.size(); i++) {
      freqency_array[nums[i] - MIN]++;
    }

    vector<int> result(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++) {
      int current = nums[i];

      int num_zeros = freqency_array[-MIN] - (current == 0 ? 1 : 0);
      if (num_zeros > 0) {
        continue;
      }

      int product = 1;
      for (int k = MIN; k <= MAX; k++) {
        if (k == 1) {
          continue;
        }

        int count = freqency_array[k - MIN] - (current == k ? 1 : 0);

        if (k == -1) {
          if (count % 2 == 1) {
            product *= -1;
          }

          continue;
        }

        while (count--) {
          product *= k;
        }
      }

      result[i] = product;
    }

    return result;
  }
};
