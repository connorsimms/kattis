#include <bits/stdc++.h>
using namespace std;

constexpr string targ{"123456789"};

int main() {
  string start(9, ' ');

  for (int i{}; i < 9; ++i)
    cin >> start[i];

  unordered_map<string, int> d;
  queue<string> q;
  q.push(start);
  d[start] = 0;

  while (!q.empty()) {
    auto &f = q.front();
    auto cd = d[f];

    for (int i{}; i < 9; ++i) {
      if (i % 3 < 2) {
        swap(f[i], f[i + 1]);
        if (!d.count(f)) {
          d[f] = cd + 1;
          q.push(f);
        }
        swap(f[i], f[i + 1]);
      }
      if (i + 3 < 9) {
        swap(f[i], f[i + 3]);
        if (!d.count(f)) {
          d[f] = cd + 1;
          q.push(f);
        }
        swap(f[i], f[i + 3]);
      }
    }

    q.pop();
  }

  cout << d[targ] << '\n';
}
