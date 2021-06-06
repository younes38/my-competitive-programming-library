
template <typename T = int64_t> 
struct min_stack {
    stack<pair<T, T>> st;
    void push(T new_elem) {
        T new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
        st.push({new_elem, new_min});
    }
    T pop() {
        T removed_element = st.top().first;
        st.pop();
        return removed_element;
    }
    T get_min() {
        T minimum = st.top().second;
        return minimum;
    }
}

// TODO test it
int main() {

}



