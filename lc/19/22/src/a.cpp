class Solution {
public:
  int countGoodNumbers(long long n) {
    long long odd = power(5, n / 2 + n % 2), even = power(4, n / 2);
    return (odd * even) % MOD;
  }

private:
  static const int MOD = 1e9 + 7;

  long long power(long long n, long long x) {
    long long result = 1;

    for (; x; x >>= 1, n = (n * n) % MOD) {
      if (x & 1) {
        result = (result * n) % MOD;
      }
    }

    return result % MOD;
  }
};
