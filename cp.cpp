// all prime numbers less than a number

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int sq = 1e6 + 1;

void solve()
{
  int n;
  cin >> n;
  bool sieve[sq] = {0};
  for (int i = 2; i*i < sq; i++) {
    if (!sieve[i]) {
        for (int j = i*i; j < sq; j += i) 
          sieve[j] = 1;
    }
  }
  for(int i = 2; i <= n; i++) {
    if(!sieve[i])
      cout<<i<<" ";
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}