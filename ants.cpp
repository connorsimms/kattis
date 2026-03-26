#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int l, n; cin >> l >> n;
        vector<int> fast(l + 1), slow(l + 1);
        for (int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            if (x < l / 2)
            {
                fast[x] = -1;
                slow[x] = 1;
            }
        }


    }
}
