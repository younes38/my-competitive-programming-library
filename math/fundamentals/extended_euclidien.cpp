#include <bits/stdc++.h>
using namespace std;


// calculate x and y for: a * x + b * y = gcd(a, b)
// x, y passed by reference  
template <typename T = int64_t> 
T gcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T x1, y1;
    T d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
    

// TODO test this
int32_t main() {
  return 0;
}