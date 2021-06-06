#include <bits/stdc++.h>
using namespace std;

struct fen_tree {
    // binary indexed tree
    vector<int> bit;  
    int n;

    fen_tree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    fen_tree(vector<int> a) : fen_tree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


// TODO test this
int32_t main() {
  return 0;
}