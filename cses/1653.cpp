#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main() {
  int n;
  cin >> n;
  ll x;
  cin >> x;

  vector<ll> w(n);
  for (int i{}; i < n; ++i) {
    cin >> w[i];
  }

  int full = (1 << n) - 1;

  // # min num rides, min weight on some ride
  vector<pair<int, int>> mem(1 << n, make_pair(INF, INF));

  auto dp = [&](auto &&rec, int set) -> pair<int, int> {
    if (mem[set].first != INF)
      return mem[set];

    if (__builtin_popcount(set) == 1) {
      int i = __builtin_ctz(set);
      mem[set].first = 1;
      mem[set].second = w[i];
      return mem[set];
    }

    for (int i{}; i < n; ++i) {
      if (set & (1 << i)) {
        auto [rides, weight] = rec(rec, set ^ (1 << i));

        if (weight + w[i] <= x) {
          if (rides < mem[set].first) {
            mem[set].first = rides;
            mem[set].second = weight + w[i];
          } else if (rides == mem[set].first &&
                     weight + w[i] < mem[set].second) {
            mem[set].second = weight + w[i];
          }
        } else {
          if (rides + 1 < mem[set].first) {
            mem[set].first = rides + 1;
            mem[set].second = w[i];
          }
        }
      }
    }

    return mem[set];
  };

  cout << dp(dp, full).first << '\n';
}
