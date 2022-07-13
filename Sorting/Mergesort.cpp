#include<bits/stdc++.h>
using namespace std;


#define ll long long
const int mod = 1e9 + 7;

void merge(int l, int mid,  int r, vector<int>&nums ) {
  vector<int>left(nums.begin() + l, nums.begin() + mid + 1);
  vector<int>right(nums.begin() + mid + 1, nums.begin() + r + 1);
  int ptr = l;
  int p1 = 0, p2 = 0;
  while (p1 < mid - l + 1 and p2 < r - mid) {
    if (left[p1] <= right[p2]) nums[ptr] = left[p1], ptr++, p1++;
    else if (left[p1] > right[p2])  nums[ptr] = right[p2], ptr++, p2++;
  }
  while (p1 < mid - l + 1) {
    nums[ptr] = left[p1], ptr++, p1++;
  }
  while (p2 < r - mid) {
    nums[ptr] = right[p2], ptr++, p2++;
  }
}

void mergesort(int l, int r, vector<int>&nums) {
  if (l == r) return;
  int mid = (l + r) / 2;
  mergesort(l, mid, nums);
  mergesort(mid + 1, r, nums);
  merge(l, mid, r, nums);
}

void solve() {
  int n;  cin >> n;
  vector<int>nums(n);
  for (int &x : nums) cin >> x;

  mergesort(0, n - 1, nums);

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
