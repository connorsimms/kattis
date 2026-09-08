#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
template <typename T> using VVV = V<VV<T>>;
template <typename T> using VVVV = V<VVV<T>>;
template <typename T> using VVVVV = V<VVVV<T>>;

int main() {
  string A, B;
  cin >> A >> B;

  vector<int> a, b;
  for (size_t i{A.size()}; i < B.size(); ++i)
    a.push_back(0);
  for (auto c : A)
    a.push_back(c - '0');
  for (auto c : B)
    b.push_back(c - '0');

  VVVVV<ll> mem(2, VVVV<ll>(2, VVV<ll>(2, VV<ll>(11, V<ll>(b.size(), -1)))));

  auto dp = [&](auto &&rec, bool ga, bool sb, bool lz, int last,
                size_t pos) -> ll {
    if (pos == b.size())
      return 1LL;

    if (mem[ga][sb][lz][last][pos] != -1)
      return mem[ga][sb][lz][last][pos];

    mem[ga][sb][lz][last][pos] = 0;

    for (int dig{}; dig <= 9; ++dig) {
      if (!lz && (dig == last))
        continue;

      if (!ga && dig < a[pos])
        continue;

      if (!sb && dig > b[pos])
        continue;

      bool new_lz = lz && (dig == 0);
      bool new_ga = ga || (dig > a[pos]);
      bool new_sb = sb || (dig < b[pos]);

      mem[ga][sb][lz][last][pos] +=
          rec(rec, new_ga, new_sb, new_lz, dig, pos + 1);
    }

    return mem[ga][sb][lz][last][pos];
  };

  cout << dp(dp, 0, 0, 1, 10, 0) << '\n';
}
