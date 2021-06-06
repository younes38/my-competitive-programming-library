#include <bits/stdc++.h>
using namespace std;


// calculate the prime numbers <= n
vector<int> primes;
void run_sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; (long long)i * i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

// TODO test this
int32_t main() {
  return 0;
}