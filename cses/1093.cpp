#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

ll exp(ll b, ll e) {
  ll res{1};
  b %= MOD;
  while (e) {
    if (e & 1)
      res = res * b % MOD;
    b = b * b % MOD;
    e >>= 1;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;

  ll tot = n * (n + 1) / 2;

  if (tot & 1) {
    cout << 0;
    return 0;
  }

  ll sub = tot / 2;

  vector<ll> mem(tot + 1);

  for (ll i{1}; i <= n; ++i) {
    for (ll j{tot}; j >= 0; --j) {
      if (mem[j])
        mem[j + i] = (mem[j + i] + mem[j]) % MOD;
    }
    mem[i] = (mem[i] + 1) % MOD;
  }

  cout << mem[sub] * exp(2, MOD - 2) % MOD << '\n';
}
