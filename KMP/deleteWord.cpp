  //Delete all occurence of a strign t from string s ,using KMP algorithm in O(N) Time Complexity
  #include<bits/stdc++.h>
  using namespace std;


  #define ll long long
  const int mod = 1e9 + 7;


  vector<int> build(string &s) {
    int n = s.size();
    int first = 0, last = 1;
    vector<int>pi(n);

    for (int i = 0; i < n; i++) {
      while (s[first] != s[last] and first != 0) {
        first = pi[first - 1];
      } 
      if (s[first] == s[last]) {
        first++;
        pi[i] = first;
      }
      last++;
    }

    return pi;
  }


  void solve() { 
    string s; cin >> s;
    string t; cin >> t;
    int n = s.size();
    vector<int>pi = build(t);
    int j = 0, res = -1;

    for (int i = 0; i < n; i++) {
      if (s[i] == t[j]) {
        if (res == -1)  res = i;
        j++;
        if (j == t.size())  {
          cout << res << endl;
          i = i - j;
          s.erase(res, j), res = -1;
          j = 0;
        }

      }
      else {
        if (j > 0) {
          res = i - pi[j - 1];
          i--;
          j = pi[j - 1];
        }
        else res = -1;
      }
    }

    for (auto x : s)  cout << x;
  }


    
  int main()
  {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
      solve();
    }
   
    return 0;
  }
