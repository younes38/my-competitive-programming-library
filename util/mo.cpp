
struct query {
  public:
  int l, r, id;  
  // S = n / sqrt(q)
  static const int BLOCK_SIZE = (int) 1e3;
  query() {}
  query(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
  bool operator<(const query& rhs) const{ 
    if (l / BLOCK_SIZE != rhs.l / BLOCK_SIZE) {
      return l < rhs.l;
    }
    return (l / BLOCK_SIZE & 1) ? (r < rhs.r) : (r > rhs.r);
  }
};
 
 
template<typename TV, typename TQ>
class MO {
  public:
  vector<TQ> Q;
  vector<TV> A;
 
  vector<int> mp;
  vector<int> stp;
 
  MO(vector<TV> &_A, vector<TQ> &_Q) : Q(_Q), A(_A) {
      mp = vector<int>(300010);
      stp = vector<int>(300010);
  }
 
  template<typename T>
  void addLeft(T &curr, int id) {
    auto v = A[id];
    auto &cnt = mp[v];
    if (cnt >= 0) 
    stp[cnt]--;
    if (cnt == curr) {
        curr++;
    }
    cnt++;
    if (cnt >= 0) 
    stp[cnt]++;
  }
 
  template<typename T>
  void addRight(T &curr, int id) {
    addLeft(curr, id);
  }
 
  template<typename T>
  void removeLeft(T &curr, int id) {
    auto v = A[id];
    auto &cnt = mp[v];
    if (cnt >= 0) 
    stp[cnt]--;
    if (cnt == curr && cnt >= 0) {
        if (stp[cnt] == 0) {
            curr = max(0, curr - 1);
        }
    }    
    
    cnt--;
    if (cnt >= 0) 
    stp[cnt]++;
  }
 
  template<typename T>
  void removeRight(T &curr, int id) {
    removeLeft(curr, id);
  }
 
  template<typename T>
  vector<T> get() {
    sort(Q.begin(), Q.end());
    int m = (int) Q.size();
    vector<T> res(m);
    T ans = T();
    int l = 0, r = -1;
    for (auto &q : Q) {
      while (l < q.l) {
        removeLeft(ans, l);
        l++;
      }
      
      while (l > q.l) {
        l--;
        addLeft(ans, l);
      }
 
      while (r < q.r) {
        r++;
        addRight(ans, r);
      }
      
      while (r > q.r) {
        removeRight(ans, r);
        r--;
      }      
      res[q.id] = ans;
    }
    return res; 
  }
};
 