#include <bits/stdc++.h>
using namespace std;

// TODO it is not tested

// multiply a and b, values are calculated modulo mod
template <typename T = int64_t>
vector<vector<T>> mul(const vector<vector<T>> &a, const vector<vector<T>> &b, T mod) {
  int rows_a = (int)a.size();
  int cols_a = (int)a[0].size();
  int rows_b = (int)b.size();
  int cols_b = (int)b[0].size();
  assert(cols_a == rows_b);
  vector<vector<T>> res(rows_a, vector<T>(cols_b, 0));
  for(int i = 0; i < rows_a; i++) {
    for(int j = 0; j < cols_b; j++) {
        for(int k = 0; k < cols_a; k++) {
          res[i][j] += (long long)a[i][k] * b[k][j] % mod + mod;
          res[i][j] %= mod;
        }
    }
  }
  return mod;
}



// calculate the power of a mutrix mod m
template <typename T = int64_t> 
vector<vector<T>> powmod(vector<vector<T>> a, long long n, long long mod) {
  int rows = a.size();
  int cols = a[0].size();
  assert(rows == cols);
  vector<vector<T>> res(rows, vector<T>(cols, 0));
  for(int i = 0; i < rows; i++) res[i][j] = 1;
  while (n > 0) {
    if (n & 1) res = mul(res, a, mod);
    a = mul(a, a, mod);
    b >>= 2;
  }
  return res;
}

// TODO test this
int32_t main() {
  return 0;
}