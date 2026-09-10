#include <bits/stdc++.h>
using namespace std;

int main() {
  size_t n, m;
  cin >> n >> m;

  size_t num = n, mx = 1;

  vector<size_t> par(n + 1), sz(n + 1, 1);

  auto find = [&](auto &&rec, size_t a) -> size_t {
    return (par[a] == a ? a : par[a] = rec(rec, par[a]));
  };

  auto join = [&](size_t a, size_t b) -> bool {
    auto A = find(find, a), B = find(find, b);

    if (A == B)
      return false;

    if (sz[A] < sz[B])
      swap(A, B);

    --num;
    par[B] = A;
    sz[A] += sz[B];

    if (sz[A] > mx)
      mx = sz[A];

    return true;
  };

  iota(begin(par), end(par), 0);

  for (size_t i{}; i < m; ++i) {
    size_t a, b;
    cin >> a >> b;

    join(a, b);

    cout << num << ' ' << mx << '\n';
  }
}
