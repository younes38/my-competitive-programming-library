#include <bits/stdc++.h>
using namespace std;
//! NOT TESTED
// TODO test it from https://cses.fi/problemset/task/1735/


// TODO change here
struct node {
    long long v, lazy_add, lazy_set;
    // initial value or out of range
    node() {
        v = 0;
        lazy_add = 0;
        lazy_set = 0;
    }
    node(long long a) {
        v = a;
        lazy_add = 0;
        lazy_set = 0;
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
    
    void _push(int v, int l, int mid, int r) {
        int lc = v >> 1;
        int rc = v >> 1 | 1;
        if(t[v].lazy_set != 0){
            t[lc].lazy_set = t[rc].lazy_set = t[v].lazy_set;
            t[lc].v = (mid - l + 1) * t[v].lazy_set;
            t[rc].v = (r - mid) * t[v].lazy_set;
            t[lc].lazy_add = t[rc].lazy_add = 0;
            t[v].lazy_set = 0;
        } else if (t[v].lazy_add != 0){ //lazy: range add
            if (t[lc].lazy_set == 0) t[lc].lazy_add += t[v].lazy_add;
            else {
                t[lc].lazy_set += t[v].lazy_add;
                t[lc].lazy_add = 0;
            }
            if (t[rc].lazy_set == 0) t[rc].lazy_add += t[v].lazy_add;
            else{
                t[rc].lazy_set += t[v].lazy_add;
                t[rc].lazy_add = 0;
            }
            t[lc].v += (mid - l + 1) * t[v].lazy_add;
            t[rc].v += (r - mid) * t[v].lazy_add;
            t[v].lazy_add = 0;
        }
    }

    node _get(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return node();
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) >> 1;
        _push(v, tl, tm, tr);
        return _combine(_get(v << 1, tl, tm, l, min(r, tm)),
             _get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void _add(int v, int tl, int tr, int l, int r, long long to_add) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v].v += (r - l + 1) * to_add;
            if (t[v].lazy_set == 0) t[v].lazy_add += to_add;
            else t[v].lazy_set += to_add;
        } else {
            int tm = (tl + tr) / 2;
            _push(v, tl, tm, tr);
            _add(v * 2, tl, tm, l, min(r, tm), to_add);
            _add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, to_add);
            t[v] = _combine(t[v * 2], t[v * 2 + 1]);
        }
    }

    void _set(int v, int tl, int tr, int l, int r, long long new_val) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v].v = (r - l + 1) * new_val;
            t[v].lazy_add = 0;
            t[v].lazy_set = new_val;
        } else {
            int tm = (tl + tr) / 2;
            _push(v, tl, tm, tr);
            _set(v * 2, tl, tm, l, min(r, tm), new_val);
            _set(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
            t[v] = _combine(t[v * 2], t[v * 2 + 1]);
        }
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
    void add(int l, int r, long long to_add) {
        _add(1, 0, n - 1, l, r, to_add);
    }

    // log(n)
    void set(int l, int r, long long new_val) {
        _set(1, 0, n - 1, l, r, new_val);
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
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, x;
            cin >> a >> b >> x;
            st.add(a - 1, b - 1, x);
        }
        if (t == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            st.set(a - 1, b - 1, x);
        }
        if (t == 3) {
            int a, b;
            cin >> a >> b;
            cout << st.get(a - 1, b - 1).v << endl;
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