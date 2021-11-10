//binary search
#include<bits/stdc++.h>
using namespace std;
void basics()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void solve()
{
	//Binary Search O(logn)
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int key;
	cin >> key;
	int count = 0;
	int l = 0, r = n - 1, mid;
	string str = "Not Present ";
	while (l <= r)
	{
		count++;
		mid = floor(l + r) / 2;
		if (arr[mid] == key)
		{
			str = "Present ";
			break;
		}
		else if (arr[mid] > key)
		{
			count++;
			r = mid - 1;
		} else {
			count++;
			l = mid + 1;
		}
	}
	cout << str << count << endl;
}
int32_t main()
{
	basics();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
