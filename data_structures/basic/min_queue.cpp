#include <bits/stdc++.h>
using namespace std;

// we don't know the popped element
struct min_queue {
    deque<pair<int, int>> q;
    int cnt_added = 0;
    int cnt_removed = 0;
    int get() {
        int minimum = q.front().first;
        return minimum;
    }

    void push() {
        while (!q.empty() && q.back().first > new_element)
            q.pop_back();
        q.push_back({new_element, cnt_added});
        cnt_added++;
    }

    void pop() {
        if (!q.empty() && q.front().second == cnt_removed) 
            q.pop_front();
        cnt_removed++;
    }
}