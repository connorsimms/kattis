#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<tuple<int, int, ll>> e;

  for (int i{}; i < n; ++i) {
    int a, b, p;
    cin >> a >> b >> p;
    e.emplace_back(a, b, p);
  }

  sort(begin(e), end(e));

  vector<ll> mem(n);

  auto dp = [&](auto &&rec, int id) {
    if (mem[id])
      return mem[id];

    if (id == n)
      return mem[id] = get<2>(e.back());

    auto [a, b, p] = e[id];

    mem[id] = max(mem[id], rec(rec, id + 1));

    auto it = lower_bound(begin(e), end(e), make_tuple(b + 1, b + 1, 0));

    if (it == end(e))
      mem[id] = max(mem[id], p);
    else
      mem[id] = max(mem[id], rec(rec, it - begin(e)) + p);

    return mem[id];
  };

  cout << dp(dp, 0) << '\n';
}
