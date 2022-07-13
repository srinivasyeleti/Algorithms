//Heap sort
//Time complexity for Heap Sort is O(n*log(n))
//BUILD HEAP-->O(N) TIME COMPLEXITY ANALYSIS :
//https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

void maxheapify(int i, int size, vector<int>&nums) {
    if (i < size)  {
        int greatest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size and nums[greatest] < nums[left])  greatest = left;
        if (right < size and nums[greatest] < nums[right]) greatest = right;
        if (greatest != i)  {
          swap(nums[greatest], nums[i]);
          maxheapify(greatest, size, nums);
        }
    }
}

void heapsort(vector<int>&nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--) { //Build heap -->O(n)
      maxheapify(i, n, nums);
    }

    for (int i = 0; i < n ; i++) {
      swap(nums[0], nums[n - 1 - i]);
      maxheapify(0, n - 1 - i, nums);
    }

}

void solve() {
  int n;  cin >> n;
  vector<int>nums(n);
  for (int &x : nums) cin >> x;
  heapsort(nums);
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
