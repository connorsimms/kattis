#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <typename T> using V = vector<T>;

constexpr ll MOD = 1e9 + 7;

int main() {
  int M, D;
  cin >> M >> D;

  string A, B;
  cin >> A >> B;

  vector<int> a, b;
  for (auto c : A)
    a.push_back(c - '0');
  for (auto c : B)
    b.push_back(c - '0');

  V<V<V<V<ll>>>> mem =
      V<V<V<V<ll>>>>(2, V<V<V<ll>>>(2, V<V<ll>>(M, V<ll>(b.size(), -1))));

  auto dp = [&](auto &&rec, bool ga, bool sb, int mod, size_t pos) -> ll {
    if (pos == b.size())
      return mod == 0;

    auto &res = mem[ga][sb][mod][pos];

    if (res != -1)
      return res;

    res = 0;

    for (int d{}; d <= 9; ++d) {
      if ((d == D) != (pos & 1)) {
        continue;
      }

      if (!ga && d < a[pos])
        continue;

      if (!sb && d > b[pos])
        continue;

      int new_ga = ga || d > a[pos];
      int new_sb = sb || d < b[pos];
      int new_mod = (mod * 10 % M + d) % M;

      res += rec(rec, new_ga, new_sb, new_mod, pos + 1);
      res %= MOD;
    }

    return res;
  };

  cout << dp(dp, 0, 0, 0, 0) << '\n';
}
