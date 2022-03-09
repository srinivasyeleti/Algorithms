#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxt = 2e5, maxn = 1e7;
bool comp[maxn + 10];
int sq = 1e6 + 1;

set<long long> solve()
{
  bool sieve[sq] = {0};
  for (int i = 2; i*i < sq; i++) {
    if (!sieve[i]) {
        for (int j = i*i; j < sq; j += i) 
          sieve[j] = 1;
    }
  }
  set<long long>s;
  for (int i = 2; i < sq; i++) {
    if (!sieve[i])
      s.insert((long long)i*i);
  }
  return s;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  set<long long>s(solve());
  int n; cin>>n;
  for (int i = 0; i < n; i++) {
      long long  v;
      cin >> v;
      if(s.count(v))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
  }
  return 0;
}


































// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//    srand((unsigned) time(NULL));
//    for (int i = 0; i < 160; i++) {
//       cout << 1 + rand() % 1000 << " ";
//    }

//    return 0;
// }





