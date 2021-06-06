#include <bits/stdc++.h>
using namespace std;


// calculate the prime numbers <= n
vector<int> primes;
void run_sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

template <typename T = int64_t> 
vector<T> factorize(T n) {
    vector<T> factors;
    for (T d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

// TODO test this
int32_t main() {
  return 0;
}