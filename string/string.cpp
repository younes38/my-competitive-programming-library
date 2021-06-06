// return an array which for every index(i) a number represents the maximum length 
// such that prefix == suffix in the string Z[0:i]
//example : if Z = "aba#ababa" : the it returns : 0 0 1 0 1 2 3 2 3 
vector<int> prefix_function (string Z) {
    int n = (int) Z.length();
    vector<int> F (n);
    F[0]=0;
    for (int i=1; i<n; ++i) {
        int j = F[i-1];
        while (j > 0 && Z[i] != Z[j])
            j = F[j-1];

        if (Z[i] == Z[j])  ++j;

        F[i] = j;
    }
    return F;
}
//palindrome exp : ABCBA
bool pali (string s) {
  int n = s.size() ;
  for (int i = 0  ; i< n/2 ;i++) {
    if (s[i]!=s[n-i-1]) return false ;
  }
  return true ;
}

string baseString(const string &s)
{
    string bs(s);
    // Remove all empty spaces and sort the string.
    bs.erase(remove(bs.begin(), bs.end(), ' '), bs.end());
    sort(bs.begin(), bs.end());
    return bs;
}