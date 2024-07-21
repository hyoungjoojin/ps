// 4 ms, 15.92 MB

#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0;

    int current_stock = -1;
    for (int i = 0; i < prices.size() - 1; i++) {
      if (prices[i] < prices[i + 1]) {
        if (current_stock == -1)
          current_stock = prices[i];
        continue;
      }

      if (current_stock == -1)
        continue;

      profit += (prices[i] - current_stock);
      current_stock = -1;
    }

    if (current_stock != -1)
      profit += (prices[prices.size() - 1] - current_stock);

    return profit;
  }
};
