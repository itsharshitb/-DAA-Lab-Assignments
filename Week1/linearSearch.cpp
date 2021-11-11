//linear search
#include<bits/stdc++.h>
using namespace std;
#define w(x) int  x; cin>>x; while(x--)
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
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int key;
	cin >> key;
	int count = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key) {
			count = i + 1;
		}
	}
	if (count != -1)
		cout << "Present " << count << endl;
	else
		cout << "Not Present " << n << endl;
}
int32_t main()
{
	basics();
	w(t)
	{
		solve();
	}
	return 0;
}