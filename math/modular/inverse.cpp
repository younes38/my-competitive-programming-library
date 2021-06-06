#include <bits/stdc++.h>
using namespace std;


// extended euclidien
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


// inverse of a mod m
template <typename T = int64_t> 
T inverse(T a, T m) {
    T x, y;
    T g = extended_euclidean(a, m, x, y);
    if (g != 1) return -1;
    else {
        x = (x % m + m) % m;
        return x;
    }
}

// inverse of all number from 1 to m - 1 (mod m)
vector<int> inverse(int m) {
    vector<int> inv(m);
    inv[1] = 1;
    for(int i = 2; i < m; ++i)
        inv[i] = m - (m / i) * inv[m % i] % m;
    return inv;
}

// TODO test this
int32_t main() {
  return 0;
}