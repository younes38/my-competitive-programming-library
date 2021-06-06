#include <bits/stdc++.h>
using namespace std;


// calculate a ** b % m in log(b) time
template <typename T = int64_t> 
T powmod(T a, T b, T m) {
  a %= m;
  T res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

// TODO test this
int32_t main() {
  return 0;
}