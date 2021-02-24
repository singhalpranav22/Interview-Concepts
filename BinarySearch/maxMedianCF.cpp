// D. Max Median
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are a given an array 𝑎 of length 𝑛. Find a subarray 𝑎[𝑙..𝑟] with length at least 𝑘 with the largest median.

// A median in an array of length 𝑛 is an element which occupies position number ⌊𝑛+12⌋ after we sort the elements in non-decreasing order. For example: 𝑚𝑒𝑑𝑖𝑎𝑛([1,2,3,4])=2, 𝑚𝑒𝑑𝑖𝑎𝑛([3,2,1])=2, 𝑚𝑒𝑑𝑖𝑎𝑛([2,1,2,1])=1.

// Subarray 𝑎[𝑙..𝑟] is a contiguous part of the array 𝑎, i. e. the array 𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟 for some 1≤𝑙≤𝑟≤𝑛, its length is 𝑟−𝑙+1.

// Input
// The first line contains two integers 𝑛 and 𝑘 (1≤𝑘≤𝑛≤2⋅105).

// The second line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤𝑛).

// Output
// Output one integer 𝑚 — the maximum median you can get.

// Examples
// inputCopy
// 5 3
// 1 2 3 2 1
// outputCopy
// 2
// inputCopy
// 4 2
// 1 2 3 4
// outputCopy
// 3
// Note
// In the first examp   le all the possible subarrays are [1..3], [1..4], [1..5], [2..4], [2..5] and [3..5] and the median for all of them is 2, so the maximum possible median is 2 too.

// In the second example 𝑚𝑒𝑑𝑖𝑎𝑛([3..4])=3.


// Pranav Singhal (IIIT-ALLAHABAD)
// May the Force be with You :
// Binary Search & min prefix sum tech
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define send                          \
  {                                   \
    ios_base::sync_with_stdio(false); \
  }
#define help        \
  {                 \
    cin.tie(NULL);  \
    cout.tie(NULL); \
  }
#define nl "\n"
int main()
{
  send help
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll n, k;
  cin >> n >> k;
  ll a[n + 1];
  ll mx = INT_MIN;
  for (ll i = 1; i <= n; i++)
  {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  if (n == 1)
  {
    cout << mx << nl;
    exit(0);
  }
  ll l = 1, r = mx + 1;
  while (r - l > 1)
  {
    ll mid = (l + r) / 2;
    // cout<<l<<" "<<r<<nl;
    // now check if 'mid' can be a median or not
    int aux[n + 1];
    for (ll i = 1; i <= n; i++)
    {
      if (a[i] >= mid)
        aux[i] = 1;
      else
        aux[i] = -1;
    }
    // calculate presum array for using min prefix technique
    for (ll i = 2; i <= n; i++)
      aux[i] = aux[i - 1] + aux[i];
    ll mn = 0;
    ll mx = aux[k];
    for (ll i = k + 1; i <= n; i++)
    {
      if (mn > aux[i - k])
        mn = aux[i - k];
      mx = max(mx, aux[i] - mn);
    }
    // cout<<mid<<" "<<mx<<nl;
    if (mx > 0) // median 'mid' possible
    {
      l = mid;
    }
    else
    { // median 'mid' not possible
      r = mid;
    }
  }
  cout << l << nl;

  return 0;
}