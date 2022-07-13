//quick sort with run time O(n*log(n)) on average and O(n^2)  in worst case.
//space complexity O(log(n)) for partition function in worst case.

#include<bits/stdc++.h>
using namespace std;


#define ll long long
const int mod = 1e9 + 7;

int partition(int l, int r, vector<int>&nums) {
  int p_index = r;
  int st = l - 1;
  for (int i = l; i < r; i++) {
    if (nums[i] < nums[r])  st++, swap(nums[i], nums[st]);
  }
  swap(nums[st + 1], nums[r]);
  return st + 1;
}


void quicksort(int l, int r, vector<int>&nums) {
  while (l < r) {
      int p = partition(l, r, nums);
      int left_size = p - l;
      int right_size = r - p;
      if (left_size <= right_size)  quicksort(l, p - 1, nums), l = p + 1;
      else  quicksort(p + 1, r,nums), r = p - 1;
  }
}

void solve() {
  int n;  cin >> n;
  vector<int>nums(n);
  for (int &x : nums) cin >> x;
  quicksort(0, n - 1, nums);
  for (int x : nums)  cout << x << " ";
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
