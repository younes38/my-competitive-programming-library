

#include <bits/stdc++.h>
using namespace std;


// calculate gcd(a, b)
template <typename T = int64_t> 
T gcd (T a, T b) {
    return b ? gcd (b, a % b) : a;
}


// TODO test this
int32_t main() {
  return 0;
}