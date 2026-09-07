#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll NINF = numeric_limits<ll>::min();

int main() {
  size_t n;
  cin >> n;

  vector<ll> v(n), pf(n);

  for (size_t i{}; i < n; ++i) {
    cin >> v[i];
    pf[i] = v[i];

    if (i)
      pf[i] += pf[i - 1];
  }

  vector<vector<ll>> mem(n, vector<ll>(n, NINF));

  auto dp = [&](auto &&rec, int l, int r) {
    if (mem[l][r] != NINF)
      return mem[l][r];

    if (l == r) {
      return mem[l][r] = v[l];
    }

    auto tot = pf[r];
    if (l)
      tot -= pf[l - 1];

    mem[l][r] = max(mem[l][r], tot - rec(rec, l + 1, r));
    mem[l][r] = max(mem[l][r], tot - rec(rec, l, r - 1));

    return mem[l][r];
  };

  cout << dp(dp, 0, n - 1) << '\n';
}
