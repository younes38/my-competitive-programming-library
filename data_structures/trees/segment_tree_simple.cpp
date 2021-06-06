#include <bits/stdc++.h>
using namespace std;

// debug library
// #ifdef ONLINE_JUDGE
// #define cerr if (false) cerr
// #define debug(...) 99
// #else
// #include "./library/debug.h"
// #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// #endif

// other defines
#define mem(A, v) memset(A, v, sizeof(A));

// some pre defined nodes (with thier combine)
// *** [Finding subsegments with the maximal sum] *** 
// struct node {
//     long long sum, pref, suff, ans;
//     node(long long a) {
//         res.sum = val;
//         res.pref = res.suff = res.ans = max(0, a);
//         return res;
//     }
//     node() {
//         return node(0LL);
//     }
// };
// node combine(node l, node r) {
//     node res;
//     res.sum = l.sum + r.sum;
//     res.pref = max(l.pref, l.sum + r.pref);
//     res.suff = max(r.suff, r.sum + l.suff);
//     res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
//     return res;
// }


const int INF = 1e9 + 5;
// TODO change here
struct node {
    long long v;
    // initial value or out of range
    node() {
        v = 0;
    }
    node(long long a) {
        v = a;
    }
};
struct seg_tree {
    int n;
    vector<node> t;
    // private
    // TODO change here
    node _combine(node a, node b) {
        node res;
        res.v = a.v + b.v;
        return res;
    }

    void _build(const vector<long long>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = node(a[tl]);
        } else {
            int tm = (tl + tr) >> 1;
            _build(a, v << 1, tl, tm);
            _build(a, v << 1 | 1, tm + 1, tr);
            t[v] = _combine(t[v << 1], t[v << 1 | 1]); 
        }
    }

    node _get(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return node();
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) >> 1;
        return _combine(_get(v << 1, tl, tm, l, min(r, tm)),
             _get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void _set(int v, int tl, int tr, int pos, long long new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                _set(v << 1, tl, tm, pos, new_val);
            else
                _set(v << 1 | 1, tm + 1, tr, pos, new_val);
            t[v] = _combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    int _find_kth(int v, int tl, int tr, int k) { 
        if (k > t[v])
            return -1;
        if (tl == tr)
            return tl;
        int tm = (tl + tr) >> 1;
        if (t[v << 1] >= k)
            return find_kth(v << 1, tl, tm, k);
        else 
            return find_kth(v << 1 | 1, tm + 1, tr, k - t[v << 1]);
    }
    
    // public
    // O(n)
    seg_tree(int n) {
        this->n = n;
        t.assign(4 * n, node());
    }

    // O(n)
    seg_tree(const vector<long long>& a) {
        n = (int)a.size();
        t.assign(4 * n, node());
        _build(a, 1, 0, n - 1);
    }

    // log(n)
    node get(int l, int r) {
        return _get(1, 0, n - 1, l, r);
    }

    // log(n)
    node get(int pos) {
        return _get(1, 0, n - 1, pos, pos);
    }

    // log(n)
    void set(int pos, long long new_val) {
        _set(1, 0, n - 1, pos, new_val);
    }

    // log(n)
    void add(int pos, long long to_add) {
        long long new_val = get(pos).v + to_add;
        set(pos, new_val);
    }
    
    // TODO test it
    // log(n)
    int find_kth(int l, int r, int k) { 
        return _find_kth(1, l, r, k);
    }
};



// TODO complete this function
void solve(int qq) {
    int n, q; 
    cin >> n >> q;
    vector<long long> A(n);
    for(auto &a: A) cin >> a;
    seg_tree st(A);
    while (q--) {
        int t, a, b;
        
        cin >> t >> a >> b ;
        if (t == 0) {
            st.add(a, b);
        } else {
            b--;
            cout << st.get(a, b).v << endl;
        }
    }
    
}


int32_t main() {
    // TODO remove this for interactive problems
    // ios::sync_with_stdio(false); 
    // cin.tie(0);   

    int t = 1;
    int q = 1;
    // TODO remove this if there is one test case
    // cin >> t;
    while (t-- > 0) solve(q++);

    return 0;
}