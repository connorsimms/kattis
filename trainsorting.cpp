#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> weight(n);

    for(int i = 0 ; i < n ; ++i)
    {
	cin >> weight[i];
    }

    vector<int> mem_left(n);
    vector<int> mem_right(n);

    for(int i = n - 1 ; i >= 0 ; --i)
    {
	mem_left[i] = 1;

	for(int j = i + 1 ; j < n; ++j)
	{
	    if(weight[j] < weight[i]) { // add to left side
		mem_left[i] = max(mem_left[i], mem_left[j] + 1);	
	    }
	}
    }

    for(int i = n - 1 ; i >= 0; --i)
    {
	mem_right[i] = 1;

	for(int j = i + 1 ; j < n; ++j)
	{
	    if(weight[j] > weight[i]) { // add to left side
		mem_right[i] = max(mem_right[i], mem_right[j] + 1);	
	    }
	}
    }

    int ans = 0;

    for(int i = 0 ; i < n ; ++i)
    {
	ans = max(ans, mem_left[i] + mem_right[i] - 1);
    }

    cout << ans << '\n';
}
