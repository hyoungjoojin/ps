// 5 ms, 11.43 MB

#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> temp(m + n, 0);

    int nums1_index = 0, nums2_index = 0, temp_index = 0;
    while (nums1_index < m && nums2_index < n) {
      if (nums1[nums1_index] < nums2[nums2_index])
        temp[temp_index++] = nums1[nums1_index++];
      else
        temp[temp_index++] = nums2[nums2_index++];
    }

    while (nums1_index < m)
      temp[temp_index++] = nums1[nums1_index++];

    while (nums2_index < n)
      temp[temp_index++] = nums2[nums2_index++];

    for (int i = 0; i < m + n; i++)
      nums1[i] = temp[i];
  }
};
